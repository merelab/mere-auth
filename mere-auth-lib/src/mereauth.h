#ifndef MEREAUTH_H
#define MEREAUTH_H

#include "mereauthglobal.h"
#include "mereapplicant.h"

#include <QDebug>
#include <QObject>

class MerePAM;

class MERE_AUTH_LIBSPEC MereAuth : public QObject
{
    Q_OBJECT
public:
    explicit MereAuth(QObject *parent = nullptr);
    bool authenticate(const QString &username, const QString &password);
    bool logout();

signals:

public slots:

private:
    MerePAM *m_pam;

};

#endif // MEREAUTH_H
