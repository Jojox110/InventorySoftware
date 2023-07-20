#include "widget.h"
#include <pqxx/pqxx>
#include <QApplication>
#include <iostream>
#include <QDebug>
#include <QString>
#include "StoreItem_Class.cpp"

using namespace pqxx;

int main(int argc, char *argv[])
{

    connection c ("dbname = postgres user = postgres password = 859RHU6A9hUWSimi host = db.wvokvvnurrnibmbzpsff.supabase.co port = 5432");

    std::string sql = "SELECT name FROM Items";

    nontransaction N(c);
    result R(N.exec(sql));

    StoreItem banana = StoreItem(1,0.89,4.7,"Banana","Food","Fruit");
    QString bananaName = banana.getName();
    qInfo()<< bananaName;
    banana.setPrice(-70);
    double newPrice = banana.getPrice();
    qInfo() << QString::number(newPrice);

    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
