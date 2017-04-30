#include <item-manager.h>

void ItemManager::addItem(const Item& item)
{
    months[currentMonth].addItem(item);
}

void ItemManager::removeItem(const Item& item)
{
    months[currentMonth].removeItem(item);
}

void ItemManager::editItem(const Item& old, const Item& edited)
{
    months[currentMonth].editItem(old, edited);
}

const QString& ItemManager::month() const
{
    return currentMonth;
}

void ItemManager::month(const QString& month_) {
    if (QDateTime::fromString(month_, dateFormat).isValid()) {
        currentMonth = month_;
    } else {
        throw std::runtime_error("Formato do mês inválido");
    }
}

QList<Item> ItemManager::sortedMonthItems() const
{
    return months[currentMonth].sortedItems();
}
