#include "items.h"

void Items::addItem(const Item& item)
{
    insert(item.name(), item);
    emit changed();
}


void Items::removeItem(const Item& item)
{
    remove(item.name());
    emit changed();
}
