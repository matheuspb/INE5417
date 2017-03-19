#include "entrywidget.h"

EntryWidget::EntryWidget(QWidget *parent):
    QTreeWidget(parent)
{
    updateEntries();
}

void EntryWidget::updateEntries()
{
    incomes.addChildren(list.getIncomes());
    expenses.addChildren(list.getExpenses());
}
