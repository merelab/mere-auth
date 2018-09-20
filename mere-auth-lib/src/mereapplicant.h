#ifndef MEREACCOUNT_H
#define MEREACCOUNT_H

#include <QObject>

class MereApplicant : public QObject
{
    Q_OBJECT
public:
    explicit MereApplicant(const QString &username, const QString &password, QObject *parent = nullptr);

    const QString &username();
    const QString &password();

signals:

public slots:
private:
    const QString &m_username;
    const QString &m_password;
};

#endif // MEREACCOUNT_H
