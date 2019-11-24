#include "mereuser.h"
#include "mereuserprofile.h"

MereUser::MereUser()
{

}

unsigned int MereUser::uid() const
{
    return m_uid;
}

void MereUser::setUid(unsigned int uid)
{
    m_uid = uid;
}

unsigned int MereUser::gid() const
{
    return m_gid;
}

void MereUser::setGid(unsigned int gid)
{
    m_gid = gid;
}

QString MereUser::name() const
{
    return m_name;
}

void MereUser::setName(QString name)
{
    m_name = name;
}

QList<unsigned int > MereUser::groups() const
{
    return m_groups;
}

void MereUser::setGroups(QList<unsigned int > groups)
{
    m_groups.clear();
    m_groups.append(groups);
}

QString MereUser::klass() const
{
    return m_klass;
}

MereUserProfile MereUser::profile()
{
    return m_profile;
}

void MereUser::setProfile(MereUserProfile profile)
{
    m_profile = profile;
}
