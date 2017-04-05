#ifndef ITEMLIST_H
#define ITEMLIST_H

#include <QObject>
#include <QTreeWidgetItem>
#include <QList>

#include "item.h"

class ItemList : public QObject
{
    Q_OBJECT

public:
    ItemList() = default;

    const QList<Item>& getIncomes() const;
    const QList<Item>& getExpenses() const;

    void removeItem(Item);

public slots:
    void addExpense();
    void addIncome();

signals:
    void listChanged();

private:
    QList<Item> incomes;
    QList<Item> expenses;

};

#endif // ITEMLIST_H
