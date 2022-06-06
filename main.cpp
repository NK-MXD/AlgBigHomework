#include "mainwindow.h"
#include"googleoauth.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //GoogleOAuth g;
    //g.show();
    return a.exec();
}
