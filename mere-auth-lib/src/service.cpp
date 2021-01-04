#include "service.h"
#include "applicant.h"
#include "pam/pam.h"

#include "mere/utils/stringutils.h"

Mere::Auth::Service::~Service()
{
    if (m_pam != nullptr)
    {
        delete m_pam;
        m_pam = nullptr;
    }
}

Mere::Auth::Service::Service(const QString &service, QObject *parent)
    : QObject(parent),
      m_service(service),
      m_pam(new PAM(m_service))
{
}

bool Mere::Auth::Service::login(const QString &username, const QString &password)
{
    if ( Mere::Utils::StringUtils::isBlank(username) || Mere::Utils::StringUtils::isBlank(password))
    {
        qDebug() << "Username and/or passord can not be empty!";
        return false;
    }

    Applicant applicant(username, password);

    int result = m_pam->login(applicant);
    if (result == 0)
        emit authenticated(user(username));

    return result == 0;
}

bool Mere::Auth::Service::logout()
{
    return false;
}

Mere::Auth::User Mere::Auth::Service::user(const QString &username) const
{
    QByteArray b = username.toUtf8();
    char *u = b.data();

    return user(u);
}

Mere::Auth::User Mere::Auth::Service::user(const char *username) const
{
    Mere::Auth::User user;

    struct passwd *pw;
    if ((pw = getpwnam(username)))
    {
        user.setUid(pw->pw_uid);
        user.setGid(pw->pw_gid);
        user.setName(pw->pw_name);

        Mere::Auth::UserProfile profile;
        profile.setName(pw->pw_gecos);
        profile.setHome(pw->pw_dir);
        profile.setShell(pw->pw_shell);

        QVector<Group> groups = this->groups(pw->pw_name, pw->pw_gid);
        profile.setGroups(groups);

        user.setProfile(profile);
    }
    else
    {
        //errx(1, "%s: no such user", u);
    }

    return user;
}

QVector<Mere::Auth::Group> Mere::Auth::Service::groups(const char *username, const unsigned int &gid) const
{
    QVector<Group> groups;

    gid_t *grps;
    long ngroups_max = sysconf(_SC_NGROUPS_MAX) + 1;
    if ((grps = (unsigned int *) malloc(sizeof(gid_t) * ngroups_max)) == NULL)
    {
        //err(1, "malloc");
    }

    int ngroups = (int) ngroups_max;
    getgrouplist(username, gid, grps, &ngroups);
    for (int i = 0; i < ngroups; i++)
        groups.append(group(grps[i]));

    free(grps);

    return groups;
}

Mere::Auth::Group Mere::Auth::Service::group(const unsigned int &gid) const
{
    Group group;

    struct group *gr;
    if ((gr = getgrgid(gid)))
    {
        group.setGid(gid);
        group.setName(gr->gr_name);

        for (int i = 0; gr->gr_mem[i] != NULL; i++)
           group.addMember(gr->gr_mem[i]);
    }
    else
    {
        //errx(1, "%s: no such group", gid);
    }

    return group;
}
