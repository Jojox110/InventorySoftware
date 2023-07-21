#include "widget.h"
#include <pqxx/pqxx>
#include <QApplication>
<<<<<<< HEAD
#include <QGridLayout>
#include <QLabel>
#include <QFrame>
=======
#include <iostream>
#include <QDebug>
#include <QString>
#include "StoreItem_Class.cpp"

using namespace pqxx;
>>>>>>> 70d1ee252c15af02dce39d7270295b0320ee66dd

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
