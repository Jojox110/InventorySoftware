#include "widget.h"
#include "./ui_widget.h"

#include <pqxx/pqxx>
#include <iostream>
#include <QDebug>

#include <QLabel>
#include <QFrame>
#include <QGridLayout>
#include <cstdlib>

using namespace pqxx;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    char* value = std::getenv("TEST");
    qInfo() << value << "testing testing" << "\n";

    int col = 0;
    int row = 0;

    for (int i = 0; i < 11; i++) {
        QGridLayout *grid = new QGridLayout();
        QLabel *l1 = new QLabel("aaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbccccccccccccccccccccccccccccccccccccc");
        QLabel *l2 = new QLabel("b");
        QLabel *l3 = new QLabel("c");

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

