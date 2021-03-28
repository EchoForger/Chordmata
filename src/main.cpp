#include <QApplication>
#include <QSound>
#include "mainwindow.h"
#include "project.h"
#include "global.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
