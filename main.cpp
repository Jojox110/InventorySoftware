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
#include "GetItems.h"

using namespace pqxx;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Widget w;

    std::vector<StoreItem> items = getItems();

    w.show();
    return a.exec();
}
