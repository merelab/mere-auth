#ifndef MEREAUTH_H
#define MEREAUTH_H

#include "mereapplicant.h"

#include <QDebug>
#include <QObject>

class MerePAM;

class MereAuth : public QObject
{
    Q_OBJECT
public:
    explicit MereAuth(QObject *parent = nullptr);
    bool login(const QString &username, const QString &password);
    bool logout();

signals:

public slots:

private:
    MerePAM *m_pam;

};

#endif // MEREAUTH_H
