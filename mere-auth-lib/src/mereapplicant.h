#ifndef MEREAPPLICANT_H
#define MEREAPPLICANT_H

#include "mereauthglobal.h"
#include "mereaccount.h"

class MERE_AUTH_LIBSPEC MereApplicant
{
public:
    explicit MereApplicant(const QString username, const QString password);

    const QString username() const;
    const QString password() const;
    const MereAccount account() const;

private:
    const MereAccount m_accout;
};

#endif // MEREAPPLICANT_H
