#include "mainwidget.h"
#include "item.h"

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

    auto incomeList = list.getIncomes();
    auto expenseList = list.getExpenses();

    for (auto income: incomeList) {
        incomes.addChild(buildItem(income));
    }

    for (auto expense: expenseList) {
        expenses.addChild(buildItem(expense));
    }
}

QTreeWidgetItem* MainWidget::buildItem(const Item& item)
{
    auto treeItem = new QTreeWidgetItem({item.name(),
                                         item.category(),
                                         QString::number(item.value())});
    return treeItem;
}
