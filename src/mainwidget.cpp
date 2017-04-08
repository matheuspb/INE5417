#include "mainwidget.h"
#include "item.h"

MainWidget::MainWidget(QWidget *parent):
    QTreeWidget(parent)
{
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

    for (auto item: list.getItems()) {
        QStringList data = {item.name(), item.category(),
                          QString::number(item.value(), 'f', 2)};

        auto parent = item.type() == Item::Type::income ? &incomes : &expenses;
        new QTreeWidgetItem(parent, data, item.type());
    }
}
