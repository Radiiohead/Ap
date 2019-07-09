#include "mainwindow.h"
#pragma once
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login l;
    l.show();
    //MainWindow w;
    //w.show();
    return a.exec();
}
