#include <stk/Noise.h>
#include <QApplication>
#include <QSound>
#include "mainwindow.h"

using namespace stk;

int main(int argc, char *argv[])
{

    StkFloat output;
    Noise noise;
    for (unsigned int i = 0; i < 20; i++)
    {
        output = noise.tick();
        std::cout << "i = " << i << " : output = " << output << std::endl;
    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
