#ifndef MEREAUTH_H
#define MEREAUTH_H

#include "global.h"
#include "user/user.h"

#include <grp.h>

#include <QObject>
#include <QDebug>

namespace Mere
{
namespace Auth
{

class PAM;

class MERE_AUTH_LIBSPEC Service : public QObject
{
    Q_OBJECT
public:
    ~Service();
    explicit Service(const QString &service = "mere", QObject *parent = nullptr);
    bool login(const QString &username, const QString &password);
    bool logout();

    User user(const QString &username) const;
    User user(const char *username) const;

    Group group(const unsigned int &gid) const;
    QVector<Group> groups(const char *username, const unsigned int &gid) const;

signals:
    void authenticated(User user);

public slots:

private:
    QString m_service;
    PAM *m_pam;

};
}
}

#endif // MEREAUTH_H
