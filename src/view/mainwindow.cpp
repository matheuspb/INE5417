#include <mainwindow.h>
#include <ui_mainwindow.h>

#include <QSignalMapper>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Gerenciador de orçamentos");
    setFixedSize(size());

    connect(ui->addIncomeAction, SIGNAL(triggered()),
            this, SLOT(on_income_clicked()));
    connect(ui->addExpenseAction, SIGNAL(triggered()),
            this, SLOT(on_expense_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_deleteButton_clicked()
{
    ui->entryWidget->removeSelectedItem();
}

void MainWindow::on_editButton_clicked()
{
    ui->entryWidget->editSelectedItem();
}

void MainWindow::on_income_clicked()
{
    ui->entryWidget->addNewItem(Item::Type::income);
}

void MainWindow::on_expense_clicked()
{
    ui->entryWidget->addNewItem(Item::Type::expense);
}
