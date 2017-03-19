#ifndef ENTRYLIST_H
#define ENTRYLIST_H

#include <QObject>
#include <QTreeWidgetItem>
#include <QList>

class EntryList : public QObject
{
    Q_OBJECT

public:
    EntryList();

    const QList<QTreeWidgetItem*>& getIncomes() const;
    const QList<QTreeWidgetItem*>& getExpenses() const;

public slots:
    void addExpense();
    void addIncome();

signals:
    void listChanged();

private:
    QList<QTreeWidgetItem*> incomes;
    QList<QTreeWidgetItem*> expenses;

    static QTreeWidgetItem* buildItem(QString name, QString category,
                                      QString value);
};

#endif // ENTRYLIST_H
