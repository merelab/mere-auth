#ifndef MEREUSERPROFILE_H
#define MEREUSERPROFILE_H

#include "../mereauthglobal.h"
#include "meregroup.h"

class MERE_AUTH_LIBSPEC MereUserProfile
{
public:
    ~MereUserProfile();
    explicit MereUserProfile();
    explicit MereUserProfile(int uid);

    QString name() const;
    void setName(const QString name);

    QString home() const;
    void setHome(QString home);

    QString shell() const;
    void setShell(QString shell);

    QList<MereGroup> groups() const;
    void addGroup(const MereGroup group);
    void setGroups(const QList<MereGroup> groups);

    QString icon() const;
    QString mail() const;

private:
    unsigned int m_uid;
    QString m_name;
    QString m_home;
    QString m_shell;

    QList<MereGroup> m_groups;

    QString m_icon;
    QString m_mail;
};

#endif // MEREUSERPROFILE_H
