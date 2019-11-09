#include "mereauth.h"
#include "mereapplicant.h"
#include "pam/merepam.h"

#include "mere/utils/merestringutils.h"

MereAuth::MereAuth(QObject *parent) : QObject(parent)
{
    m_pam = new MerePAM("mere", parent);
}

bool MereAuth::login(const QString &username, const QString &password)
{
    if ( MereStringUtils::isBlank(username) || MereStringUtils::isBlank(password))
    {
        qDebug() << "Username and/or passord can not be empty!";
        return false;
    }

    MereApplicant applicant(username, password);

    int result = m_pam->login(applicant);

    return result == 0;
}

bool MereAuth::logout()
{
    return false;
}

