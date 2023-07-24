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
<<<<<<< HEAD
    StoreItem banana = StoreItem(1,0.89,4.7,"Banana","Food","Fruit");
    QString bananaName = banana.getName();
    qInfo()<< bananaName;
    banana.setPrice(-70);
    double newPrice = banana.getPrice();
    qInfo() << QString::number(newPrice);
=======
>>>>>>> 9320983b9757407751f2353aeed67b99a6326430

    QApplication a(argc, argv);
    Widget w;

    std::vector<StoreItem> items = getItems();

    w.show();
    return a.exec();
}
