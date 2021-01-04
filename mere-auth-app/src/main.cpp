#include "mere/auth/service.h"

#include <QDebug>
#include <QCommandLineParser>
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication::setApplicationName("Mere Auth");
    QCoreApplication::setApplicationVersion("0.0.1");

    QCoreApplication app(argc, argv);

    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addVersionOption();

    QCommandLineOption usernameOption(QStringList() << "u" << "username",
                                      QCoreApplication::translate("main", "Set the username"),
                                      "username");

    QCommandLineOption passwordOption(QStringList() << "p" << "password",
                                      QCoreApplication::translate("main", "Set the username"),
                                      "password");

    parser.addOption(usernameOption);
    parser.addOption(passwordOption);

    parser.process(QCoreApplication::arguments());

    QString username = parser.value(usernameOption);
    QString password = parser.value(passwordOption);

    Mere::Auth::Service auth;
    bool ok = auth.login(username, password);
    if (ok)
    {
        qDebug() << "Yes, a valid user of this system.";

        Mere::Auth::User user = auth.user(username);
        qDebug() << "Username:" << user.name();
        qDebug() << "Uid:" << user.uid();
        qDebug() << "Gid:" << user.gid();
        qDebug() << "Name:" << user.profile().name();

        Mere::Auth::UserProfile profile = user.profile();
        for (const auto &group : profile.groups())
        {
            qDebug() << "Gid:" << group.gid();
            qDebug() << "Name:" << group.name();
            for (const auto &member : group.members())
            {
                qDebug() << "Member:" << member;
            }
        }

        ::exit(0);
    }
    else
    {
        qDebug() << "Sorry, not a valid user of this system.";
        ::exit(1);
    }

    return app.exec();
}
