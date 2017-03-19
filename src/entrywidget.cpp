#include "entrywidget.h"

EntryWidget::EntryWidget(QWidget *parent):
    QTreeWidget(parent)
{
    updateEntries();

    QObject::connect(&list, SIGNAL(listChanged()),
                     this, SLOT(updateEntries()));
}

const EntryList& EntryWidget::getList() const
{
    return list;
}

void EntryWidget::updateEntries()
{
    incomes.addChildren(list.getIncomes());
    expenses.addChildren(list.getExpenses());
}
