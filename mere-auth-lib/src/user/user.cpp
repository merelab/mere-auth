#include "user.h"
#include "userprofile.h"

Mere::Auth::User::User()
{

}

unsigned int Mere::Auth::User::uid() const
{
    return m_uid;
}

void Mere::Auth::User::setUid(unsigned int uid)
{
    m_uid = uid;
}

unsigned int Mere::Auth::User::gid() const
{
    return m_gid;
}

void Mere::Auth::User::setGid(unsigned int gid)
{
    m_gid = gid;
}

QString Mere::Auth::User::name() const
{
    return m_name;
}

void Mere::Auth::User::setName(QString name)
{
    m_name = name;
}

QVector<unsigned int > Mere::Auth::User::groups() const
{
    return m_groups;
}

void Mere::Auth::User::setGroups(QVector<unsigned int > groups)
{
    m_groups.clear();
    m_groups.append(groups);
}

QString Mere::Auth::User::klass() const
{
    return m_klass;
}

Mere::Auth::UserProfile Mere::Auth::User::profile() const
{
    return m_profile;
}

void Mere::Auth::User::setProfile(Mere::Auth::UserProfile profile)
{
    m_profile = profile;
}
