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
    void on_editButton_clicked();
    void on_deleteButton_clicked();
    void on_income_clicked();
    void on_expense_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
