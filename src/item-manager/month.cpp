#include <month.h>

void Month::addItem(const Item& item)
{
    itemsMap.insert(item.name(), item);
}


void Month::removeItem(const Item& item)
{
    // erase just removes one item
    itemsMap.erase(itemsMap.find(item.name(), item));
}

void Month::editItem(const Item& old, const Item& edited)
{
    removeItem(old);
    addItem(edited);
}

QList<Item> Month::sortedItems() const
{
    return itemsMap.values();
}
