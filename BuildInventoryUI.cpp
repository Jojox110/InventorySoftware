#include "BuildInventoryUI.h"

#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QWidget>

BuildInventoryUI::BuildInventoryUI(QGridLayout *mainGrid, QGridLayout *itemGrid, int col, int row) {
    this->mainGrid = mainGrid;
    this->itemGrid = itemGrid;
    this->col = 0;
    this->row = 0;
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

    QGridLayout *itemDescription;
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

void BuildInventoryUI::addPagesGrid() {
    // TODO: find a row/col position
    // Put under itemGrid
}

void BuildInventoryUI::addFilterComboBox() {
    // TODO: find a row/col position
    // Put above the far right corner of the itemGrid
}
