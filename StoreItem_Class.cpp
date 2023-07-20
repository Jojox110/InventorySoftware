#include <QApplication>
#include <iostream>
#include <QDebug>
#include <QString>

class StoreItem{
private:
//ATRIBUTES
    long Id;
    double Price;
    double Rating;
    QString Name;
    QString Main_Category;
    QString Sub_Category;

public:
 //GETTERS AND SETTERS
    long getId(){
        return Id;
    }

    void setPrice(double price){
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
    double getPrice(){
        return Price;
    }

    void setRating(double rating){
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
    double getRating(){
        return Rating;
    }

    void setName(QString name){
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
    QString getName(){
        return Name;
    }

    void setMain_Category(QString main_category){
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
    QString getMain_Category(){
        return Main_Category;
    }

    void setSub_Category(QString sub_category){
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
    QString getSub_Category(){
        return Sub_Category;
    }

//CONSTRUCTOR
    StoreItem(long id, double price, double rating, QString name, QString main_category, QString sub_category){
        Id = id;
        Price = price;
        Rating = rating;
        Name = name;
        Main_Category = main_category;
        Sub_Category = sub_category;
    }
};
