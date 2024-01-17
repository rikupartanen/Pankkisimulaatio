#include "mainwindow.h"
#include <QDialog>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mw;
    mw.show();
    return a.exec();
}

// readAll() lukee serialporttia
