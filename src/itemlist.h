#ifndef ITEMLIST_H
#define ITEMLIST_H

#include <QObject>
#include <QTreeWidgetItem>
#include <QList>

#include "item.h"

class ItemList : public QObject
{
    Q_OBJECT

public:
    ItemList() = default;

    QList<Item> getItems(Item::Type type = Item::Type::none) const;

    void addItem(const Item&);
    void removeItem(const Item&);
    void updateItem(const Item&, const Item&);

signals:
    void listChanged();

private:
    QList<Item> items;

};

#endif // ITEMLIST_H
