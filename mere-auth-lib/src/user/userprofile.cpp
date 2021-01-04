#include "userprofile.h"

Mere::Auth::UserProfile::~UserProfile()
{

}

Mere::Auth::UserProfile::UserProfile()
{

}

Mere::Auth::UserProfile::UserProfile(int uid)
    : m_uid(uid)
{

}

QString Mere::Auth::UserProfile::name() const
{
    return m_name;
}

void Mere::Auth::UserProfile::setName(const QString name)
{
    m_name = name;
}

QString Mere::Auth::UserProfile::home() const
{
    return m_home;
}

void Mere::Auth::UserProfile::setHome(QString home)
{
    m_home = home;
}

QString Mere::Auth::UserProfile::shell() const
{
    return m_shell;
}

void Mere::Auth::UserProfile::setShell(QString shell)
{
    m_shell = shell;
}

QVector<Mere::Auth::Group> Mere::Auth::UserProfile::groups() const
{
    return m_groups;
}

void Mere::Auth::UserProfile::addGroup(const Group group)
{
    m_groups.append(group);
}

void Mere::Auth::UserProfile::setGroups(const QVector<Group> groups)
{
    m_groups.clear();
    m_groups.append(groups);
}

QString Mere::Auth::UserProfile::icon() const
{
    return m_icon;
}

QString Mere::Auth::UserProfile::mail() const
{
    return m_mail;
}
