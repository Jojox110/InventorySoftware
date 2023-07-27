#ifndef BUILDINVENTORYUI_H
#define BUILDINVENTORYUI_H

#include "StoreItem_Class.h"

#include <QGridLayout>
#include <QObject>


class BuildInventoryUI : public QObject
{
    Q_OBJECT
    QGridLayout *mainGrid;
    QGridLayout *itemGrid;
    int col;
    int row;
    int pageNum;
    std::vector<StoreItem> items;

public:
    BuildInventoryUI(QGridLayout *mainGrid, QGridLayout *itemGrid, int col, int row, std::vector<StoreItem> items);
    void addItemsGrid();
    void addItemToItemsGrid(StoreItem item);
    void refillGrid();
    void clearItemsGrid();
    void addFilterComboBox();
    void addPagesGrid();
    int getPageNum();

public slots:
    void increasePageNum();
    void decreasePageNum();
};

#endif // BUILDINVENTORYUI_H
