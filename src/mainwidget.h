#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QTreeWidget>
#include "itemlist.h"

class MainWidget : public QTreeWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);

    ItemList& getList();

public slots:
    void updateEntries();

private:
    ItemList list;
    QTreeWidgetItem incomes{this, {"Receitas"}};
    QTreeWidgetItem expenses{this, {"Despesas"}};

};

#endif // MAINWIDGET_H
