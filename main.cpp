#include "mainwindow.h"
#include "myt.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.show();

    MYTApp myt;
    myt.getSearch("Digital Foundry");

    return app.exec();
}
