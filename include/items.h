#ifndef ITEMLIST_H
#define ITEMLIST_H

#include <QObject>
#include <QMultiMap>

#include "item.h"

class Items : public QObject, private QMultiMap<QString, Item>
{
    Q_OBJECT

public:
    using QMap<QString, Item>::begin;
    using QMap<QString, Item>::end;

    void addItem(const Item&);
    void removeItem(const Item&);

};

#endif // ITEMLIST_H
