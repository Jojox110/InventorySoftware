#include "widget.h"
#include <pqxx/pqxx>
#include <QApplication>
#include <QGridLayout>
#include <QLabel>
#include <QFrame>
#include <iostream>
#include <QDebug>
#include <QString>
#include "StoreItem_Class.cpp"

using namespace pqxx;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
