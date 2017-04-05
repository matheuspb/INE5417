#include "itemlist.h"

ItemList::ItemList()
{
    incomes.append(buildItem("Salário", "", "1500"));

    expenses.append(buildItem("Aluguel", "Essencial", "500"));
    expenses.append(buildItem("Luz", "Essencial", "70"));
}

const QList<QTreeWidgetItem*>& ItemList::getIncomes() const
{
    return incomes;
}

const QList<QTreeWidgetItem*>& ItemList::getExpenses() const
{
    return expenses;
}

void ItemList::addExpense()
{
    expenses.append(buildItem("Despesa", "", ""));
    emit listChanged();
}

void ItemList::addIncome()
{
    incomes.append(buildItem("Receita", "", ""));
    emit listChanged();
}

QTreeWidgetItem* ItemList::buildItem(QString name, QString category,
                                      QString value)
{
    auto item = new QTreeWidgetItem({name, category, value});
    item->setFlags(item->flags() | Qt::ItemIsEditable);
    return item;
}

void ItemList::removeItem(QTreeWidgetItem* item) {
    incomes.removeOne(item);
    expenses.removeOne(item);
    emit listChanged();
}
