#ifndef ENTRYLIST_H
#define ENTRYLIST_H

#include<QTreeWidgetItem>
#include<QList>

class EntryList
{
public:
    EntryList();

    const QList<QTreeWidgetItem*>& getIncomes() const;
    const QList<QTreeWidgetItem*>& getExpenses() const;

private:
    QList<QTreeWidgetItem*> incomes;
    QList<QTreeWidgetItem*> expenses;
};

#endif // ENTRYLIST_H
