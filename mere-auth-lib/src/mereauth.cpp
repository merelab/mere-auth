#include "mereauth.h"
#include "mereapplicant.h"
#include "pam/merepam.h"

#include "mere/utils/stringutils.h"

MereAuth::MereAuth(QObject *parent) : QObject(parent)
{
    m_pam = new MerePAM("mere", parent);
}

bool MereAuth::login(const QString &username, const QString &password)
{
    if ( Mere::Utils::StringUtils::isBlank(username) || Mere::Utils::StringUtils::isBlank(password))
    {
        qDebug() << "Username and/or passord can not be empty!";
        return false;
    }

    MereApplicant applicant(username, password);

    int result = m_pam->login(applicant);
    if (result == 0)
        emit authenticated(user(username));

    return result == 0;
}

bool MereAuth::logout()
{
    return false;
}

MereUser MereAuth::user(const QString &username) const
{
    QByteArray b = username.toUtf8();
    char *u = b.data();

    return user(u);
}

MereUser MereAuth::user(const char *username) const
{
    MereUser user;

    struct passwd *pw;
    if ((pw = getpwnam(username)))
    {
        user.setUid(pw->pw_uid);
        user.setGid(pw->pw_gid);
        user.setName(pw->pw_name);

        MereUserProfile profile;
        profile.setName(pw->pw_gecos);
        profile.setHome(pw->pw_dir);
        profile.setShell(pw->pw_shell);

        QList<MereGroup> groups = this->groups(pw->pw_name, pw->pw_gid);
        profile.setGroups(groups);

        user.setProfile(profile);
    }
    else
    {
        //errx(1, "%s: no such user", u);
    }

    return user;
}

QList<MereGroup> MereAuth::groups(const char *username, const unsigned int &gid) const
{
    QList<MereGroup> groups;

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

MereGroup MereAuth::group(const unsigned int &gid) const
{
    MereGroup group;

    struct group *gr;
    if ((gr = getgrgid(gid)))
    {
        group.setGid(gid);
        group.setName(gr->gr_name);

        for (int i = 0; ; i++)
        {
           if (gr->gr_mem[i] == NULL)
               break;
           group.addMember(gr->gr_mem[i]);
       }
    }
    else
    {
        //errx(1, "%s: no such group", gid);
    }

    return group;
}
