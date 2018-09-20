#include "merepam.h"

const char* MerePAM::SERVICE_NAME = "mere";
pam_handle_t* MerePAM::handler = NULL;

MerePAM::MerePAM(QObject *parent) : QObject(parent)
{

}

int MerePAM::login(const MereApplicant &applicant)
{
    const struct pam_conv converse = { handshake, (void *) &applicant };

    int result = pam_start(SERVICE_NAME, NULL, &converse, &handler);
    if( result != PAM_SUCCESS)
    {
        //pam_end(pamh, result);
        return result;
    }

//    result = pam_set_item(pamh, PAM_USER, user);
//    if (result != PAM_SUCCESS)
//    {
//        pam_end(pamh, result);
//        return result;
//    }


//    result = pam_set_item(pamh, PAM_AUTHTOK, pass);
//    if (result != PAM_SUCCESS)
//    {
//        pam_end(pamh, result);
//        return result;
//    }

    // Authenticate the applicant
    result = pam_authenticate(handler, 0);
    if (result != PAM_SUCCESS) return result;

    result = pam_acct_mgmt(handler, 0);
    if (result != PAM_SUCCESS) return result;

    result = pam_setcred(handler, PAM_ESTABLISH_CRED);
    if (result != PAM_SUCCESS) return result;

    result = pam_open_session(handler, 0);
    if (result != PAM_SUCCESS)
    {
        pam_setcred(handler, PAM_DELETE_CRED);
        return result;
    }

    return result;
}

int MerePAM::logout()
{
    int result = pam_close_session(handler, 0);
    if (result != PAM_SUCCESS)
    {
        pam_setcred(handler, PAM_DELETE_CRED);
        return result;
    }

    result = pam_setcred(handler, PAM_DELETE_CRED);
    if (result != PAM_SUCCESS)
    {
        pam_end(handler, result);
        return result;
    }

    return result;
}

//static
int MerePAM::handshake(int num_msg, const struct pam_message **msg, struct pam_response **resp, void *appdata_ptr)
{
    if (num_msg <= 0 || num_msg > PAM_MAX_NUM_MSG)
            return (PAM_CONV_ERR);

    *resp = (struct pam_response *) calloc(num_msg, sizeof(struct pam_response));
    if (*resp == NULL) return PAM_BUF_ERR;

    MereApplicant *applicant = static_cast<MereApplicant *>(appdata_ptr);

    QString data;
    QByteArray bytes;

    for (int i = 0; i < num_msg; i++)
    {
        (*resp)[i].resp = 0;
        (*resp)[i].resp_retcode = 0;

        switch (msg[i]->msg_style)
        {
            // PAM asking for passsowd
            case PAM_PROMPT_ECHO_OFF:
                    data = applicant->password();
                    bytes = data.toLatin1();
                    (*resp)[i].resp = strdup(bytes.data());
                    if ((*resp)[i].resp == NULL)
                            return fail(num_msg, resp);
                    break;

            // PAM asking for username
            case PAM_PROMPT_ECHO_ON:
                    data = applicant->username();
                    bytes = data.toLatin1();
                    (*resp)[i].resp = strdup(bytes.data());
                    if ((*resp)[i].resp == NULL)
                            return fail(num_msg, resp);
                    break;

            case PAM_ERROR_MSG:
                    qCritical() << msg[i]->msg;
                    break;

            case PAM_TEXT_INFO:
                    qInfo() << msg[i]->msg;
                    break;

            default:
                    return fail(num_msg, resp);;
        }
    }

    return (PAM_SUCCESS);
}

//static
int MerePAM::fail(int num_msg, struct pam_response **resp)
{
    for (int i = 0; i < num_msg; i++)
    {
            if ((*resp)[i].resp != NULL)
            {
                 free((*resp)[i].resp);
                 (*resp)[i].resp=0;
            }
    }
    *resp = NULL;

    return (PAM_CONV_ERR);
}
