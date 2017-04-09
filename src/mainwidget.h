#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QTreeWidget>
#include "itemlist.h"

class MainWidget : public QTreeWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);

public slots:
    void addNewItem(int);
    void removeSelectedItem();
    void editSelectedItem();
    void updateEntries();

private:
    Item promptNewItem(const Item::Type&, const Item& = Item());
    Item getSelected() const;

    ItemList list;
    QTreeWidgetItem incomes{this, {"Receitas"}};
    QTreeWidgetItem expenses{this, {"Despesas"}};

};

#endif // MAINWIDGET_H
