#include <items.h>

void Items::addItem(const Item& item)
{
    insert(item.name(), item);
}


void Items::removeItem(const Item& item)
{
    erase(find(item.name(), item)); // erase just removes one item
}
