#ifndef MEREPAM_H
#define MEREPAM_H

#include "../mereauthglobal.h"
#include "../mereapplicant.h"

#include <pwd.h>
#include <unistd.h>
#include <sys/param.h>
#include <sys/types.h>
#include <security/pam_appl.h>

#include <QObject>
#include <QDebug>

class MERE_AUTH_LIBSPEC MerePAM : public QObject
{
    Q_OBJECT
public:
    ~MerePAM();
    explicit MerePAM(const QString &service, QObject *parent = nullptr);
    void setFlags();

    static pam_handle_t *handler;

    static int handshake(int num_msg, const struct pam_message **message, struct pam_response **resp, void *data);

    int login(const MereApplicant &applicant);
    int logout();

signals:

public slots:

private:
    static int fail(int num_msg, struct pam_response **response);

private:
    const QString &m_service;
    int m_flags;
};

#endif // MEREPAM_H
