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

static struct pam_conv pamc;

class MERE_AUTH_LIBSPEC MerePAM : public QObject
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
