#ifndef MEREUSER_H
#define MEREUSER_H

#include "../mereauthglobal.h"
#include "mereuserprofile.h"
#include "meregroup.h"

#include <QObject>

class MereUserProfile;

class MERE_AUTH_LIBSPEC MereUser
{
public:
    explicit MereUser();

    unsigned int uid() const;
    void setUid(unsigned int uid);

    unsigned int gid() const;
    void setGid(unsigned int gid);

    QString name() const;
    void setName(QString name);

    QList<unsigned int > groups() const;
    void setGroups(QList<unsigned int > groups);

    QString klass() const;

    MereUserProfile profile() const;
    void setProfile(MereUserProfile profile);

private:
    unsigned int m_uid;
    unsigned int m_gid;
    QString m_name;

    QList<unsigned int > m_groups;


    QString m_klass;

    MereUserProfile m_profile;
};
//Q_DECLARE_METATYPE(MereUser);
#endif // MEREUSER_H
