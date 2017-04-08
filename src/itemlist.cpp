#include "itemlist.h"

const QList<Item>& ItemList::getIncomes() const
{
    return incomes;
}

const QList<Item>& ItemList::getExpenses() const
{
    return expenses;
}

void ItemList::addExpense()
{
    expenses.append(Item("Despesa", "", 0.0));
    emit listChanged();
}

void ItemList::addIncome()
{
    incomes.append(Item("Receita", "", 0.0));
    emit listChanged();
}


void ItemList::removeItem(Item item) {
    incomes.removeOne(item);
    expenses.removeOne(item);
    emit listChanged();
}
