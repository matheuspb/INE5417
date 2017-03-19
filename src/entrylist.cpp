#include "entrylist.h"

EntryList::EntryList()
{
    incomes.append(new QTreeWidgetItem({"Salário", "", "1500"}));

    expenses.append(new QTreeWidgetItem({"Aluguel", "Essencial", "500"}));
    expenses.append(new QTreeWidgetItem({"Luz", "Essencial", "70"}));
}

const QList<QTreeWidgetItem*>& EntryList::getIncomes() const
{
    return incomes;
}

const QList<QTreeWidgetItem*>& EntryList::getExpenses() const
{
    return expenses;
}
