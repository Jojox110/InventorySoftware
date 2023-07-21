#include <QApplication>
#include <iostream>
#include <QDebug>
#include <QString>

#include "StoreItem_Class.h"

long StoreItem::getId() {
    return Id;
}

void StoreItem::setPrice(double price){
    if (price >= 0){
        try{
            Price = price;
        }
        catch(std::exception const &e){
            qInfo() << "ERROR: " << e.what() << "/n";
        }
    }
    else{
        qInfo() << "ERROR: The price can't be a negative number." << "/n";
    }
}

double StoreItem::getPrice(){
    return Price;
}

void StoreItem::setRating(double rating){
    if (rating >= 0 && rating <= 5){
        try{
            Rating = rating;
        }
        catch(std::exception const &e){
            qInfo() << "ERROR: " << e.what() << "/n";
        }
    }
    else{
        qInfo() << "ERROR: The rating can't be negative or greater than 5.";
    }
}

double StoreItem::getRating(){
    return Rating;
}

void StoreItem::setName(QString name){
    if(name != ""){
        try{
            Name = name;
        }
        catch(std::exception const &e){
            qInfo() << "ERROR: " << e.what() << "/n";
        }
    }
    else{
        qInfo() << "ERROR: The name can't be an emty string";
    }

}

QString StoreItem::getName(){
    return Name;
}

void StoreItem::setMain_Category(QString main_category){
    if(main_category != ""){
        try{
            Main_Category = main_category;
        }
        catch(std::exception const &e){
            qInfo() << "ERROR: " << e.what() << "/n";
        }
    }
    else{
        qInfo() << "ERROR: The main_category can't be an emty string";
    }
}

QString StoreItem::getMain_Category(){
    return Main_Category;
}

void StoreItem::setSub_Category(QString sub_category){
    if(sub_category != ""){
        try{
            Sub_Category = sub_category;
        }
        catch(std::exception const &e){
            qInfo() << "ERROR: " << e.what() << "/n";
        }
    }
    else{
        qInfo() << "ERROR: The sub_category can't be an emty string";
    }
}

QString StoreItem::getSub_Category(){
    return Sub_Category;
}

StoreItem::StoreItem(long id, double price, double rating, QString name, QString main_category, QString sub_category){
    Id = id;
    Price = price;
    Rating = rating;
    Name = name;
    Main_Category = main_category;
    Sub_Category = sub_category;
}
