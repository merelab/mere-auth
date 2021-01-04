#ifndef MEREGROUP_H
#define MEREGROUP_H

#include "../global.h"

#include <QString>

namespace Mere
{
namespace Auth
{

class MERE_AUTH_LIBSPEC Group
{
public:
    Group();

    uint32_t gid() const;
    void setGid(uint32_t gid);

    QString name() const;
    void setName(QString name);

    QVector<QString> members() const;
    void addMember(QString member);
    void setMembers(QVector<QString> members);

private:
    uint32_t       m_gid;
    QString        m_name;
    QVector<QString> m_members;
};

}
}
//Q_DECLARE_METATYPE(MereGroup);
#endif // MEREGROUP_H
