#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent):
    QTreeWidget(parent)
{
    updateEntries();

    QObject::connect(&list, SIGNAL(listChanged()),
                     this, SLOT(updateEntries()));
}

ItemList& MainWidget::getList()
{
    return list;
}

void MainWidget::updateEntries()
{
    incomes.takeChildren();
    expenses.takeChildren();

    incomes.addChildren(list.getIncomes());
    expenses.addChildren(list.getExpenses());
}
