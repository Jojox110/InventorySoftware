#include "BuildInventoryUI.h"
#include "SortingFunctions.h"

#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QObject>
#include <QWidget>

BuildInventoryUI::BuildInventoryUI(QGridLayout *mainGrid, QGridLayout *itemGrid, int col, int row, std::vector<StoreItem> items, QWidget *mainWidget, QScrollArea *window, std::vector<StoreItem> sortedItems, std::vector<StoreItem> reverseSortedItems) {
    this->mainGrid = mainGrid;
    this->itemGrid = itemGrid;
    this->col = 0;
    this->row = 0;
    this->items = items;
    this->sortedItems = sortedItems;
    this->reverseSortedItems = reverseSortedItems;
    this->mainWidget = mainWidget;
    this->pageNum = 0;
    this->window = window;
}

void BuildInventoryUI::addItemsGrid() {
    this->mainGrid->addLayout(this->itemGrid, 2, 0, 1, 1);
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
    qInfo() << "refill" << this->pageNum <<"\n";

    for (int i = 0; i < 30; i++) {
        int j = i + (30*this->pageNum);
        qInfo() << "aaaa" << j;
        StoreItem item = items[j];

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
        this->itemGrid->addLayout(itemDescription, row, col);

        col += 1;
        if (col == 3) {
            col = 0;
            row += 1;
        }
    }
    qInfo() << "here";
    this->itemGrid->update();
}

void BuildInventoryUI::refillLowToHigh() {
    for (int i = 0; i < 30; i++) {
        int j = i + (30*this->pageNum);
        qInfo() << "aaaa" << "htl" << j;
        StoreItem item = sortedItems[j];

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
        this->itemGrid->addLayout(itemDescription, row, col);

        col += 1;
        if (col == 3) {
            col = 0;
            row += 1;
        }
    }
    qInfo() << "here";
    this->itemGrid->update();
}

void BuildInventoryUI::refillHighToLow() {
    for (int i = 0; i < 30; i++) {
        int j = i + (30*this->pageNum);
        qInfo() << "aaaa" << "htl" << j;
        StoreItem item = reverseSortedItems[j];

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
        this->itemGrid->addLayout(itemDescription, row, col);

        col += 1;
        if (col == 3) {
            col = 0;
            row += 1;
        }
    }
    qInfo() << "here";
    this->itemGrid->update();
}

void BuildInventoryUI::clearItemsGrid(bool page, bool htlFilter, bool lthFilter) {
//    QWidget *widgetToDelete = this->window->takeWidget();
//    delete widgetToDelete;

//    this->mainWidget = new QWidget;
//    this->mainGrid = new QGridLayout();
    clearLayout(this->itemGrid);
    this->itemGrid = new QGridLayout();

    if (page) {
        refillGrid();
    }
    else if (htlFilter) {
        refillHighToLow();
    }
    else if (lthFilter) {
        refillLowToHigh();
    }
    addPagesGrid();
    addFilterComboBox();

    this->mainGrid->addLayout(this->itemGrid, 2, 0, 1, 1);
//    this->mainWidget->setLayout(this->mainGrid);
//    this->window->setWidget(this->mainWidget);
    this->window->update();


    qInfo() << "testing";
}

void BuildInventoryUI::addPagesGrid() {
    // TODO: find a row/col position
    // Put under itemGrid
    QGridLayout *pagesGrid = new QGridLayout();

    QPushButton *backButton = new QPushButton("Back");
    QPushButton *previousButton = new QPushButton("Previous");

    QObject::connect(backButton, &QPushButton::clicked, this, &BuildInventoryUI::decreasePageNum);
    QObject::connect(previousButton, &QPushButton::clicked, this, &BuildInventoryUI::increasePageNum);

    pagesGrid->addWidget(backButton, 0, 0);
    pagesGrid->addWidget(previousButton, 0, 1);

    mainGrid->addLayout(pagesGrid, 5, 3);
}

void BuildInventoryUI::addFilterComboBox() {
    // TODO: find a row/col position
    // Put above the far right corner of the itemGrid

    // TODO: Add options into the combo box

    QComboBox *filterComboBox = new QComboBox();
    filterComboBox->addItem("Choose a filter");
    filterComboBox->addItem("High to low");
    filterComboBox->addItem("Low to high");

    QObject::connect(filterComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &BuildInventoryUI::comboBoxIndexChange);

    mainGrid->addWidget(filterComboBox, 0, 3, 1, 1);
}

int BuildInventoryUI::getPageNum() {
    return this->pageNum;
}

void BuildInventoryUI::increasePageNum() {
    this->pageNum += 1;
    clearItemsGrid(true, false, false);
}

void BuildInventoryUI::decreasePageNum() {
    if (pageNum > 0) {
        this->pageNum -= 1;
        clearItemsGrid(true, false, false);
    }
}

void BuildInventoryUI::comboBoxIndexChange(int index) {
    if (index == 1) {
        qInfo() << "one";
        highToLowFilter();
    }
    else if (index == 2) {
        qInfo() << "two";
        lowToHighFilter();
    }
    else {
        qInfo() << "???" << index;
    }
}

void BuildInventoryUI::highToLowFilter() {
    this->pageNum = 0;
    clearItemsGrid(false, true, false);
}

void BuildInventoryUI::lowToHighFilter() {
    this->pageNum = 0;
    clearItemsGrid(false, false, true);
}

void BuildInventoryUI::clearLayout(QGridLayout* layout) {
    QLayoutItem* item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (item->layout() != nullptr)
            clearLayout(static_cast<QGridLayout*>(item->layout()));

        delete item->widget();
        delete item;
    }
}
