#ifndef MEREAUTH_H
#define MEREAUTH_H

#include "mereauthglobal.h"
#include "user/mereuser.h"

//#include <err.h>
//#include <errno.h>
#include <grp.h>
//#include <pwd.h>

#include <QObject>
#include <QDebug>

class MerePAM;

class MERE_AUTH_LIBSPEC MereAuth : public QObject
{
    Q_OBJECT
public:
    explicit MereAuth(QObject *parent = nullptr);
    bool login(const QString &username, const QString &password);
    bool logout();

    MereUser user(const QString &username) const;
    MereUser user(const char *username) const;

    MereGroup group(const unsigned int &gid) const;
    QList<MereGroup> groups(const char *username, const unsigned int &gid) const;

signals:
    void authenticated(MereUser user);

public slots:

private:
    MerePAM *m_pam;

};

#endif // MEREAUTH_H
