#include "mainwindow.h"

#include <QApplication>

// Баборико Карина 6 группа
// Задание 2 по учебной практике

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
