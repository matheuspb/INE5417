#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Gerenciador de orçamentos");
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
    auto item = Item(selected[0]->text(0), selected[0]->text(1),
            selected[0]->text(2).toDouble());
    ui->entryWidget->getList().removeItem(item);
    auto s = selected[0]->text(0);
}
