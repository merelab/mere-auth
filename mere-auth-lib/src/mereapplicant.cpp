#include "mereapplicant.h"

MereApplicant::MereApplicant(const QString &username, const QString &password, QObject *parent)
    : QObject(parent),
      m_username(username),
      m_password(password)
{

}

const QString &MereApplicant::username()
{
    return m_username;
}

const QString &MereApplicant::password()
{
    return m_password;
}
