#ifndef BUILDINVENTORYUI_H
#define BUILDINVENTORYUI_H

#include "StoreItem_Class.h"

#include <QGridLayout>
#include <QObject>
#include <QScrollArea>


class BuildInventoryUI : public QObject
{
    Q_OBJECT
    QGridLayout *mainGrid;
    QGridLayout *itemGrid;
    QWidget *mainWidget;
    int col;
    int row;
    int pageNum;
    std::vector<StoreItem> items;
    std::vector<StoreItem> sortedItems;
    std::vector<StoreItem> reverseSortedItems;
    QScrollArea *window;

public:
    BuildInventoryUI(QGridLayout *mainGrid, QGridLayout *itemGrid, int col, int row, std::vector<StoreItem> items, QWidget *mainWidget, QScrollArea *window, std::vector<StoreItem> sortedItems, std::vector<StoreItem> reverseSortedItems);
    void addItemsGrid();
    void addItemToItemsGrid(StoreItem item);
    void refillGrid();
    void refillHighToLow();
    void refillLowToHigh();
    void clearItemsGrid(bool pages, bool htlFilter, bool lthFilter);
    void addFilterComboBox();
    void addPagesGrid();
    int getPageNum();
    void highToLowFilter();
    void lowToHighFilter();
    void removeLayout(QWidget *widget);
    void removeGrid(QGridLayout *grid);
    void clearLayout(QGridLayout *layout);

public slots:
    void increasePageNum();
    void decreasePageNum();
    void comboBoxIndexChange(int index);
};

#endif // BUILDINVENTORYUI_H
