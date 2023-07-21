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
<<<<<<< HEAD
=======
    StoreItem banana = StoreItem(1,0.89,4.7,"Banana","Food","Fruit");
    QString bananaName = banana.getName();
    qInfo()<< bananaName;
    banana.setPrice(-70);
    double newPrice = banana.getPrice();
    qInfo() << QString::number(newPrice);

>>>>>>> 0ebd28382a4259fa0f10171160c4e8caf4edd501
    QApplication a(argc, argv);
    Widget w;

    StoreItem item (1, 2, 3, "banana", "fruit", "food");
    qInfo() << item.getName() << "\n";

    w.show();
    return a.exec();
}
