#ifndef MEREPAM_H
#define MEREPAM_H

#include "../mereapplicant.h"
#include <security/pam_appl.h>

#include <QDebug>
#include <QObject>

static struct pam_conv pamc;

class MerePAM : public QObject
{
    Q_OBJECT
public:
    explicit MerePAM(QObject *parent = nullptr);

    static const char* SERVICE_NAME;
    static pam_handle_t *handler;

    static int handshake(int num_msg, const struct pam_message **msg, struct pam_response **resp, void *appdata_ptr);

    int login(const MereApplicant &applicant);
    int logout();

signals:

public slots:

private:
    static int fail(int num_msg, struct pam_response **resp);
};

#endif // MEREPAM_H
