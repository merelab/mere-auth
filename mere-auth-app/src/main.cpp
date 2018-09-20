#include "mereauth.h"

#include <QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MereAuth auth;
    bool ok = auth.login("iklash", "iklash22");
    if (ok)
        qDebug() << "Yes valid user!";
    else
        qDebug() << "Sorry you don't have acces to this system!";
    return a.exec();
}
