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

double ItemManager::totalIncome() const
{
    return total(Item::Type::income);
}

double ItemManager::totalExpenses() const
{
    return total(Item::Type::expense);
}

double ItemManager::total(Item::Type type) const
{
    auto items = months[currentMonth].sortedItems();
    double sum = 0;

    for (auto item: items) {
        if (item.type() == type)
            sum += item.value();
    }

    return sum;
}

QHash<QString, double> ItemManager::totalCategories() const
{
    QHash<QString, double> categoriesTotal;

    for (auto i: sortedMonthItems()) {
        if (i.type() == Item::Type::expense) {
            if (!categoriesTotal.contains(i.category()))
                categoriesTotal.insert(i.category(), i.value());
            else
                categoriesTotal[i.category()] += i.value();
        }
    }

    return categoriesTotal;
}
