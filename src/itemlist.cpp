#include "itemlist.h"

QList<Item> ItemList::getItems(Item::Type type) const
{
    if (type == Item::Type::none) {
        return items;
    } else {
        QList<Item> incomes;
        for (auto item: items) {
            if (item.type() == type)
                incomes.append(item);
        }
        return incomes;
    }
}

void ItemList::addItem(const Item& item)
{
    items.append(item);
    emit listChanged();
}


void ItemList::removeItem(const Item& item)
{
    items.removeAll(item);
    emit listChanged();
}

void ItemList::updateItem(const Item& current, const Item& other)
{
    auto i = items.indexOf(current);
    items[i] = other;
    emit listChanged();
}
