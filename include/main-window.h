#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <item.h>

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
    // buttons on the bottom of the window
    void on_changeMonthButton_clicked();
    void on_editButton_clicked();
    void on_deleteButton_clicked();

    // dropdown menu buttons
    void income_clicked();
    void expense_clicked();
    void stats_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
