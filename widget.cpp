#include "widget.h"
#include "./ui_widget.h"

#include <pqxx/pqxx>
#include <iostream>
#include <QDebug>

#include <QLabel>
#include <QFrame>
#include <QGridLayout>
#include <cstdlib>
#include <cmath>

#include "StoreItem_Class.h"
#include "GetItems.h"

using namespace pqxx;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    std::vector<StoreItem> items = getItems();

    int col = 0;
    int row = 0;

    for (int i = 0; i < 11; i++) {
        QString name = items[i].getName();
        QString price = QString::number(items[i].getPrice());
        QString rating = QString::number(items[i].getRating());

        if (std::isnan(items[i].getRating())) {
            rating = "No ratings";
        }

        QGridLayout *grid = new QGridLayout();
        QLabel *l1 = new QLabel(name);
        QLabel *l2 = new QLabel(price);
        QLabel *l3 = new QLabel(rating);

        grid->addWidget(l1, 0, 0, 1, 1);
        grid->addWidget(l2, 1, 0, 1, 1);
        grid->addWidget(l3, 2, 0, 1, 1);

        QFrame *frame = new QFrame();
        frame->setFrameStyle(QFrame::Box | QFrame::Raised);
        frame->setLineWidth(2);
        frame->setLayout(grid);

        ui->itemLayout->addWidget(frame, row, col, 1, 1);
        col += 1;
        if (col == 3) {
            col = 0;
            row += 1;
        }
    }

    ui->filterComboBox->addItem("High to Low");
    ui->filterComboBox->addItem("Low to High");
    ui->filterComboBox->addItem("A to Z");
    ui->filterComboBox->addItem("Z to A");
}

Widget::~Widget()
{
    delete ui;
}

/*    QGridLayout *gridLayout = new QGridLayout();

    int col = 0;
    int row = 0;

    for (int i = 0; i < 11; i++) {
        QGridLayout *grid = new QGridLayout();
        QLabel *l1 = new QLabel("a");
        QLabel *l2 = new QLabel("b");
        QLabel *l3 = new QLabel("c");

        grid->addWidget(l1, 0, 0, 1, 1);
        grid->addWidget(l2, 1, 0, 1, 1);
        grid->addWidget(l3, 2, 0, 1, 1);

        QFrame *frame = new QFrame();
        frame->setFrameStyle(QFrame::Box | QFrame::Raised);
        frame->setLineWidth(2);
        frame->setLayout(grid);

        ui->gridLayout->addWidget(frame, row, col, 1, 1);
        col += 1;
        if (col == 3) {
            col = 0;
            row += 1;
        }
    }

    w.setLayout(gridLayout); */

