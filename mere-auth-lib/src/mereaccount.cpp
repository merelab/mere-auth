#include "mereaccount.h"

MereAccount::MereAccount()
{

}

MereAccount::MereAccount(QString username, QString password)
    : m_username(username),
      m_password(password)
{

}

QString MereAccount::username() const
{
    return m_username;
}

void MereAccount::setUsername(const QString username)
{
    m_username = username;
}

QString MereAccount::password() const
{
    return m_password;
}

void MereAccount::setPassword(const QString password)
{
    m_password = password;
}

