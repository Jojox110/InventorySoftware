#include "widget.h"
#include <pqxx/pqxx>
#include <QApplication>
#include <QGridLayout>
#include <QLabel>
#include <QFrame>
#include <iostream>
#include <QDebug>
#include <QString>
#include "StoreItem_Class.h"

using namespace pqxx;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    StoreItem item (1, 2, 3, "banana", "fruit", "food");
    qInfo() << item.getName() << "\n";

    w.show();
    return a.exec();
}
