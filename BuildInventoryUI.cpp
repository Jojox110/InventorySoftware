#include "BuildInventoryUI.h"

#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QObject>
#include <QWidget>

BuildInventoryUI::BuildInventoryUI(QGridLayout *mainGrid, QGridLayout *itemGrid, int col, int row, std::vector<StoreItem> items) {
    this->mainGrid = mainGrid;
    this->itemGrid = itemGrid;
    this->col = 0;
    this->row = 0;
    this->items = items;
}

void BuildInventoryUI::addItemsGrid() {
    mainGrid->addLayout(itemGrid, 2, 0, 1, 1);
}

void BuildInventoryUI::addItemToItemsGrid(StoreItem item) {
    QString name = item.getName();
    QString main_category = item.getMain_Category();
    QString price = QString::number(item.getPrice());
    QString rating = QString::number(item.getRating());
    // QString::number converts from int/float/double... to QString

    QLabel *nameLbl = new QLabel(name);
    QLabel *main_categoryLbl = new QLabel(main_category);
    QLabel *priceLbl = new QLabel(price);
    QLabel *ratingLbl = new QLabel(rating);
    // Labels need to be pointers, otherwise addWidget will push out an error. The QStrings that the label uses does not need to be pointers

    nameLbl->setMaximumWidth(500);
    main_categoryLbl->setMaximumWidth(500);
    priceLbl->setMaximumWidth(500);
    ratingLbl->setMaximumWidth(500);

    QGridLayout *itemDescription = new QGridLayout();
    // addWidget(QWdiget*, row, col, rowspan, colspan)
    itemDescription->addWidget(nameLbl, 0, 0);
    itemDescription->addWidget(main_categoryLbl, 1, 0);
    itemDescription->addWidget(priceLbl, 2, 0);
    itemDescription->addWidget(ratingLbl, 3, 0);


    // addLayout has the same params as addWidget but for layouts like Horizontal Layout, Grid, Vertical Layout ...
    // TODO: Put the row/col for the grid at the proper spot
    itemGrid->addLayout(itemDescription, row, col);

    col += 1;
    if (col == 3) {
        col = 0;
        row += 1;
    }
}

void BuildInventoryUI::refillGrid() {
    qInfo() << "refill" << "\n";

    for (int i = 30*this->pageNum; i < 30*this->pageNum; i++) {
        StoreItem item = items[i];

        QString name = item.getName();
        QString main_category = item.getMain_Category();
        QString price = QString::number(item.getPrice());
        QString rating = QString::number(item.getRating());
        // QString::number converts from int/float/double... to QString

        QLabel *nameLbl = new QLabel(name);
        QLabel *main_categoryLbl = new QLabel(main_category);
        QLabel *priceLbl = new QLabel(price);
        QLabel *ratingLbl = new QLabel(rating);
        // Labels need to be pointers, otherwise addWidget will push out an error. The QStrings that the label uses does not need to be pointers

        nameLbl->setMaximumWidth(500);
        main_categoryLbl->setMaximumWidth(500);
        priceLbl->setMaximumWidth(500);
        ratingLbl->setMaximumWidth(500);

        QGridLayout *itemDescription = new QGridLayout();
        // addWidget(QWdiget*, row, col, rowspan, colspan)
        itemDescription->addWidget(nameLbl, 0, 0);
        itemDescription->addWidget(main_categoryLbl, 1, 0);
        itemDescription->addWidget(priceLbl, 2, 0);
        itemDescription->addWidget(ratingLbl, 3, 0);


        // addLayout has the same params as addWidget but for layouts like Horizontal Layout, Grid, Vertical Layout ...
        // TODO: Put the row/col for the grid at the proper spot
        itemGrid->addLayout(itemDescription, row, col);

        col += 1;
        if (col == 3) {
            col = 0;
            row += 1;
        }
    }
    mainGrid->addLayout(this->itemGrid, 2, 0, 1, 1);
    mainGrid->update();
}

void BuildInventoryUI::clearItemsGrid() {
    QLayoutItem *child;
    while ((child = this->itemGrid->takeAt(0)) != 0) {
        qInfo() << "aaaaaaaaaaaaaaaaaaa" << "\n";
        // If the taken item is a widget, delete it
        if (child->widget()) {
            qInfo() << "testing testing testing" << "\n";
            delete child->widget();
        }
        // Delete the layout item
        delete child;
    }

    this->mainGrid->removeItem(itemGrid);
    this->itemGrid = new QGridLayout();
    this->mainGrid->update();
}

void BuildInventoryUI::addPagesGrid() {
    // TODO: find a row/col position
    // Put under itemGrid
    QGridLayout *pagesGrid = new QGridLayout();

    QPushButton *backButton = new QPushButton("Back");
    QPushButton *previousButton = new QPushButton("Previous");

    QObject::connect(backButton, &QPushButton::clicked, this, &BuildInventoryUI::decreasePageNum);
    QObject::connect(previousButton, &QPushButton::clicked, this,&BuildInventoryUI::increasePageNum);

    pagesGrid->addWidget(backButton, 0, 0);
    pagesGrid->addWidget(previousButton, 0 ,1);

    mainGrid->addLayout(pagesGrid, 5, 3);
}

void BuildInventoryUI::addFilterComboBox() {
    // TODO: find a row/col position
    // Put above the far right corner of the itemGrid

    // TODO: Add options into the combo box

    QComboBox *filterComboBox = new QComboBox();
    mainGrid->addWidget(filterComboBox, 0, 3, 1, 1);
}

int BuildInventoryUI::getPageNum() {
    return this->pageNum;
}

void BuildInventoryUI::increasePageNum() {
    this->pageNum += 1;
    clearItemsGrid();
    refillGrid();
}

void BuildInventoryUI::decreasePageNum() {
    this->pageNum -= 1;
}
