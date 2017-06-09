#ifndef ITEM_MANAGER_H
#define ITEM_MANAGER_H

#include <QHash>
#include <QDateTime>

#include <month.h>
#include <item-mapper.h>

const static char dateFormat[] =  "MM/yyyy";

class ItemManager
{

public:
    ItemManager();

    void addItem(const Item&);
    void removeItem(const Item&);
    void editItem(const Item&, const Item&);

    const QString& month() const;
    void month(const QString&);

    QList<Item> sortedMonthItems() const;
    double totalIncome() const;
    double totalExpenses() const;

    QHash<QString, double> totalCategories() const;

private:
    double total(Item::Type) const;

    QString currentMonth{QDateTime::currentDateTime().toString(dateFormat)};
    QHash<QString, Month> months;

    ItemMapper itemMapper;

};

#endif // ITEM_MANAGER_H
