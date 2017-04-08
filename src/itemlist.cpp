#include "itemlist.h"

const QList<Item>& ItemList::getIncomes() const
{
    return incomes;
}

const QList<Item>& ItemList::getExpenses() const
{
    return expenses;
}

void ItemList::addExpense(const Item& item)
{
    expenses.append(item);
    emit listChanged();
}

void ItemList::addIncome(const Item& item)
{
    incomes.append(item);
    emit listChanged();
}


void ItemList::removeItem(const Item& item) {
    incomes.removeOne(item);
    expenses.removeOne(item);
    emit listChanged();
}
