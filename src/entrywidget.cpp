#include "entrywidget.h"

EntryWidget::EntryWidget(QWidget *parent):
    QTreeWidget(parent)
{
    updateEntries();

    QObject::connect(&list, SIGNAL(listChanged()),
                     this, SLOT(updateEntries()));
}

EntryList& EntryWidget::getList()
{
    return list;
}

void EntryWidget::updateEntries()
{
    incomes.takeChildren();
    expenses.takeChildren();

    incomes.addChildren(list.getIncomes());
    expenses.addChildren(list.getExpenses());
}
