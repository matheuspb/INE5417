#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(size());

    QObject::connect(ui->addExpenseAction, SIGNAL(triggered()),
                     &ui->entryWidget->getList(), SLOT(addExpense()));

    QObject::connect(ui->addIncomeAction, SIGNAL(triggered()),
                     &ui->entryWidget->getList(), SLOT(addIncome()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_deleteButton_clicked()
{
    auto selected = ui->entryWidget->selectedItems();
    ui->entryWidget->getList().removeEntry(selected[0]);
}
