#ifndef ITEMLIST_H
#define ITEMLIST_H

#include <QObject>
#include <QTreeWidgetItem>
#include <QList>

class ItemList : public QObject
{
    Q_OBJECT

public:
    ItemList();

    const QList<QTreeWidgetItem*>& getIncomes() const;
    const QList<QTreeWidgetItem*>& getExpenses() const;

public slots:
    void addExpense();
    void addIncome();
    void removeItem(QTreeWidgetItem*);

signals:
    void listChanged();

private:
    QList<QTreeWidgetItem*> incomes;
    QList<QTreeWidgetItem*> expenses;

    static QTreeWidgetItem* buildItem(QString name, QString category,
                                      QString value);
};

#endif // ITEMLIST_H
