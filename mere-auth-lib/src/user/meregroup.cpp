#include "meregroup.h"

MereGroup::MereGroup()
{

}

uint32_t MereGroup::gid() const
{
    return m_gid;
}

void MereGroup::setGid(uint32_t gid)
{
    m_gid = gid;
}

QString MereGroup::name() const
{
    return m_name;
}

void MereGroup::setName(QString name)
{
    m_name = name;
}

QList<QString> MereGroup::members() const
{
    return m_members;
}

void MereGroup::addMember(QString member)
{
    m_members.append(member);
}

void MereGroup::setMembers(QList<QString> members)
{
    m_members.clear();
    m_members.append(members);
}
