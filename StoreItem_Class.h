#ifndef STOREITEM_CLASS_H
#define STOREITEM_CLASS_H

#include <QString>

class StoreItem {
private:
    // ATTRIBUTES
    long Id;
    double Price;
    double Rating;
    QString Name;
    QString Main_Category;
    QString Sub_Category;

public:
    // GETTERS AND SETTERS
    long getId();
    void setPrice(double price);
    double getPrice();
    void setRating(double rating);
    double getRating();
    void setName(QString name);
    QString getName();
    void setMain_Category(QString Main_Category);
    QString getMain_Category();
    void setSub_Category(QString Sub_Category);
    QString getSub_Category();
    StoreItem(long id, double price, double rating, QString name, QString main_category, QString sub_category);
};

#endif // STOREITEM_CLASS_H
