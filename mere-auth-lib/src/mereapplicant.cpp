#include "mereapplicant.h"

MereApplicant::MereApplicant(const QString username, const QString password)
    : m_accout(username, password)
{

}

const MereAccount MereApplicant::account() const
{
    return m_accout;
}

const QString MereApplicant::username() const
{
    return m_accout.username();
}

const QString MereApplicant::password() const
{
    return m_accout.password();
}
