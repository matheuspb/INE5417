#include <mainwindow.h>
#include <ui_mainwindow.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Gerenciador de orçamentos");
    setFixedSize(size());

    connect(ui->addIncomeAction, SIGNAL(triggered(bool)),
            this, SLOT(income_clicked()));
    connect(ui->addExpenseAction, SIGNAL(triggered(bool)),
            this, SLOT(expense_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_deleteButton_clicked()
{
    ui->itemsWidget->removeSelectedItem();
}

void MainWindow::on_editButton_clicked()
{
    ui->itemsWidget->editSelectedItem();
}

void MainWindow::income_clicked()
{
    ui->itemsWidget->addNewItem(Item::Type::income);
}

void MainWindow::expense_clicked()
{
    ui->itemsWidget->addNewItem(Item::Type::expense);
}

void MainWindow::on_changeMonthButton_clicked()
{
    ui->itemsWidget->changeMonth();
}
