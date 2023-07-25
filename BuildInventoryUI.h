#ifndef BUILDINVENTORYUI_H
#define BUILDINVENTORYUI_H

#include "StoreItem_Class.h"

#include <QGridLayout>


class BuildInventoryUI
{
    QGridLayout *mainGrid;
    QGridLayout *itemGrid;
    int col;
    int row;

public:
    BuildInventoryUI(QGridLayout *mainGrid, QGridLayout *itemGrid, int col, int row);
    void addItemsGrid();
    void addItemToItemsGrid(StoreItem item);
    void addFilterComboBox();
    void addPagesGrid();
};

#endif // BUILDINVENTORYUI_H
