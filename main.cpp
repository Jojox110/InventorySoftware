#include "widget.h"
#include <pqxx/pqxx>
#include <QApplication>
#include <QGridLayout>
#include <QLabel>
#include <QFrame>
#include <iostream>
#include <QDebug>
#include <QString>
#include <QScrollArea>
#include "StoreItem_Class.h"
#include "GetItems.h"
#include "BuildInventoryUI.h"
#include "SortingFunctions.h"
#include <vector>

using namespace pqxx;

int main(int argc, char *argv[])
{
    StoreItem banana = StoreItem(1,0.89,4.7,"Banana","Food","Fruit");
    QString bananaName = banana.getName();
    qInfo()<< bananaName;
    banana.setPrice(-70);
    double newPrice = banana.getPrice();
    qInfo() << QString::number(newPrice);

    QApplication a(argc, argv);
    Widget w;

    // TODO: itemGrid needs a QScrollArea

    std::vector<StoreItem> items = getItems();
    std::vector<StoreItem> arr = getItems();

    int n = arr.size();
    quickSort(arr, 0, n - 1);

    std::vector<StoreItem> reverseSortedItems = reverseSortedVector(arr);


    QScrollArea *window = new QScrollArea();
    QWidget *mainWidget = new QWidget();

    QGridLayout *mainGrid = new QGridLayout();
    QGridLayout *itemGrid = new QGridLayout();

    BuildInventoryUI inventoryUI (mainGrid, itemGrid, 0, 0, items, mainWidget, window, arr, reverseSortedItems);
    inventoryUI.addItemsGrid();
    inventoryUI.addPagesGrid();
    inventoryUI.addFilterComboBox();
    for (int i = 0; i < 30; i++) {
        inventoryUI.addItemToItemsGrid(items[i]);
    }

    mainWidget->setLayout(mainGrid);
    window->setWidget(mainWidget);

    window->show();

    return a.exec();
}
