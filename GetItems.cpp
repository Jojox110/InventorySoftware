#include <iostream>
#include <vector>
#include <QString>
#include "GetItems.h"
#include "StoreItem_Class.h"
#include <QDebug>
#include <pqxx/pqxx>

using namespace pqxx;

std::vector<StoreItem> getItems() {
    std::vector<StoreItem> items;

    std::string dbname(std::getenv("DBNAME"));
    std::string user(std::getenv("USER"));
    std::string password(std::getenv("PASSWORD"));
    std::string host(std::getenv("HOST"));
    std::string port(std::getenv("PORT"));

    qInfo() << dbname << user << password << host << port << "\n";

    std::string connString = "dbname = " + dbname + " user = " + user + "  password = " + password + " host = " + host + " port = " + port;
    connection conn (connString);

    qInfo() << connString << "\n";

    std::string sql = "SELECT * FROM items";

    nontransaction N(conn);
    result R(N.exec(sql));

    for (result::const_iterator a = R.begin(); a != R.end(); ++a) {
        long id = a[0].as<long>();
        double price = a[1].as<double>();
        double rating = a[2].as<double>();
        QString name = QString::fromStdString((a[3].as<std::string>()));
        QString main_category = QString::fromStdString((a[4].as<std::string>()));
        QString sub_category = QString::fromStdString((a[5].as<std::string>()));

        StoreItem item (id, price, rating, name, main_category, sub_category);
        items.push_back(item);
    }
    qInfo() << "items length" << items.size() << "\n";
    return items;
}
