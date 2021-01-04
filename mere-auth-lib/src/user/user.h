#ifndef MEREUSER_H
#define MEREUSER_H

#include "../global.h"
#include "userprofile.h"
#include "group.h"

#include <QObject>

namespace Mere
{
namespace Auth
{

class MERE_AUTH_LIBSPEC User
{
public:
    explicit User();

    unsigned int uid() const;
    void setUid(unsigned int uid);

    unsigned int gid() const;
    void setGid(unsigned int gid);

    QString name() const;
    void setName(QString name);

    QVector<unsigned int > groups() const;
    void setGroups(QVector<unsigned int > groups);

    QString klass() const;

    UserProfile profile() const;
    void setProfile(UserProfile profile);

private:
    unsigned int m_uid;
    unsigned int m_gid;
    QString m_name;

    QVector<unsigned int > m_groups;


    QString m_klass;

    UserProfile m_profile;
};

}
}

//Q_DECLARE_METATYPE(MereUser);
#endif // MEREUSER_H
