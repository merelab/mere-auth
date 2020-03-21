#ifndef MEREGROUP_H
#define MEREGROUP_H

#include "../mereauthglobal.h"

#include <QList>
#include <QString>

class MERE_AUTH_LIBSPEC MereGroup
{
public:
    MereGroup();

    uint32_t gid() const;
    void setGid(uint32_t gid);

    QString name() const;
    void setName(QString name);

    QList<QString> members() const;
    void addMember(QString member);
    void setMembers(QList<QString> members);

private:
    uint32_t       m_gid;
    QString        m_name;
    QList<QString> m_members;
};
//Q_DECLARE_METATYPE(MereGroup);
#endif // MEREGROUP_H
