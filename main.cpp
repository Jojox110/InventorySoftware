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
#include "GetItems.h"
#include "SortingFunctions.h"
#include <vector>

using namespace pqxx;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Widget w;

    std::vector<StoreItem> arr = getItems();

    int n = arr.size();
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        qInfo() << arr[i].getPrice() << " ";
    }

    w.show();
    return a.exec();
}
