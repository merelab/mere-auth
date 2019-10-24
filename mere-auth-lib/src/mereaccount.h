#ifndef MEREACCOUNT_H
#define MEREACCOUNT_H

#include "mereauthglobal.h"

#include <QString>

class MERE_AUTH_LIBSPEC MereAccount
{
public:
    MereAccount();
    MereAccount(QString username, QString password);

    QString username() const;
    void setUsername(const QString username);

    QString password() const;
    void setPassword(const QString password);

private:
    QString m_username;
    QString m_password;
};

#endif // MEREACCOUNT_H
