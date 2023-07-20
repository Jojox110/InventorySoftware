#include "widget.h"
#include "./ui_widget.h"

#include <pqxx/pqxx>
#include <iostream>
#include <QDebug>

using namespace pqxx;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    connection c ("dbname = postgres user = postgres password = 859RHU6A9hUWSimi host = db.wvokvvnurrnibmbzpsff.supabase.co port = 5432");

    std::string sql = "SELECT * FROM info";

    nontransaction N(c);
    result R(N.exec(sql));

    int count = 0;
    for (result::const_iterator a = R.begin(); a != R.end(); ++a) {
        if (count == 0) {
            QString one = QString::fromStdString(to_string(a[0]));
            ui->label1->setText(one);
            count += 1;
            qDebug() << one;
        }

        else if (count == 1) {
            QString two = QString::fromStdString(to_string(a[0]));
            ui->label2->setText(two);
            count += 1;
            qDebug() << two;
        }
    }
}

