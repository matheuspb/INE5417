#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "item.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_deleteButton_clicked();
    void on_editButton_clicked();

    void promptForIncome();
    void promptForExpense();

private:
    Item getSelected() const;
    Item promptNewItem(const QString&, const Item::Type&, const Item& = Item());

    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
