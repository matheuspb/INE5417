#ifndef ITEMS_WIDGET_H
#define ITEMS_WIDGET_H

#include <QTreeWidget>

#include <item-manager.h>

class ItemsWidget : public QTreeWidget
{
    Q_OBJECT

public:
    explicit ItemsWidget(QWidget *parent = 0);

    void addNewItem(const Item::Type&);
    void removeSelectedItem();
    void editSelectedItem();
    void updateEntries();

    void changeMonth();

private:
    Item promptNewItem(const Item::Type&, const Item& = Item());
    Item getSelected() const;

    ItemManager itemManager;
    QTreeWidgetItem incomes{this, {"Receitas"}};
    QTreeWidgetItem expenses{this, {"Despesas"}};

};

#endif // ITEMS_WIDGET_H
