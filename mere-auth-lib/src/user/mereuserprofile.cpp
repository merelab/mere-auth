#include "mereuserprofile.h"

MereUserProfile::~MereUserProfile()
{

}

MereUserProfile::MereUserProfile()
{

}

MereUserProfile::MereUserProfile(int uid)
    : m_uid(uid)
{

}

QString MereUserProfile::name() const
{
    return m_name;
}

void MereUserProfile::setName(const QString name)
{
    m_name = name;
}

QString MereUserProfile::home() const
{
    return m_home;
}

void MereUserProfile::setHome(QString home)
{
    m_home = home;
}

QString MereUserProfile::shell() const
{
    return m_shell;
}

void MereUserProfile::setShell(QString shell)
{
    m_shell = shell;
}

QList<MereGroup> MereUserProfile::groups() const
{
    return m_groups;
}

void MereUserProfile::addGroup(const MereGroup group)
{
    m_groups.append(group);
}

void MereUserProfile::setGroups(const QList<MereGroup> groups)
{
    m_groups.clear();
    m_groups.append(groups);
}

QString MereUserProfile::icon() const
{
    return m_icon;
}

QString MereUserProfile::mail() const
{
    return m_mail;
}
