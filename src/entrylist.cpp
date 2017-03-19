#include "entrylist.h"

EntryList::EntryList()
{
    incomes.append(buildItem("Salário", "", "1500"));

    expenses.append(buildItem("Aluguel", "Essencial", "500"));
    expenses.append(buildItem("Luz", "Essencial", "70"));
}

const QList<QTreeWidgetItem*>& EntryList::getIncomes() const
{
    return incomes;
}

const QList<QTreeWidgetItem*>& EntryList::getExpenses() const
{
    return expenses;
}

void EntryList::addExpense()
{
    expenses.append(buildItem("Despesa", "", ""));
    emit listChanged();
}

void EntryList::addIncome()
{
    incomes.append(buildItem("Receita", "", ""));
    emit listChanged();
}

QTreeWidgetItem* EntryList::buildItem(QString name, QString category,
                                      QString value)
{
    auto item = new QTreeWidgetItem({name, category, value});
    item->setFlags(item->flags() | Qt::ItemIsEditable);
    return item;
}
