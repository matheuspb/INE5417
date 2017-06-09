#ifndef ITEMMAPPER_H
#define ITEMMAPPER_H

#include <QtSql>

#include <item.h>

class ItemMapper
{

public:
    ItemMapper();

    QSet<QPair<QString, Item>> fetchAllItems() const;
    void insertItem(const Item&, const QString&) const;
    void deleteItem(const QString& name) const;

private:
    QSqlDatabase db;

};

#endif // ITEMMAPPER_H
