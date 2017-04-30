#ifndef MONTH_H
#define MONTH_H

#include <QObject>
#include <QMultiMap>

#include <item.h>

class Month
{

public:
    void addItem(const Item&);
    void removeItem(const Item&);
    void editItem(const Item&, const Item&);

    QList<Item> sortedItems() const;

private:
    QMultiMap<QString, Item> itemsMap; // item.name -> item

};

#endif // MONTH_H
