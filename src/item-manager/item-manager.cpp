#include <item-manager.h>

void ItemManager::addItem(const Item& item)
{
    itemsMap.insert(item.name(), item);
}


void ItemManager::removeItem(const Item& item)
{
    // erase just removes one item
    itemsMap.erase(itemsMap.find(item.name(), item));
}

void ItemManager::editItem(const Item& old, const Item& edited)
{
    removeItem(old);
    addItem(edited);
}

QList<Item> ItemManager::sortedItems() const
{
    return itemsMap.values();
}
