#ifndef ENTRYWIDGET_H
#define ENTRYWIDGET_H

#include <QTreeWidget>
#include "entrylist.h"

class EntryWidget : public QTreeWidget
{
    Q_OBJECT

public:
    explicit EntryWidget(QWidget *parent = 0);

public slots:
    void updateEntries();

private:
    EntryList list;
    QTreeWidgetItem incomes{this, {"Receitas"}};
    QTreeWidgetItem expenses{this, {"Despesas"}};

};

#endif // ENTRYWIDGET_H
