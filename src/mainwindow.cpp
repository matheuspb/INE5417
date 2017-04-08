#include <QInputDialog>

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
                     this, SLOT(promptForExpense()));

    QObject::connect(ui->addIncomeAction, SIGNAL(triggered()),
                     this, SLOT(promptForIncome()));
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

void MainWindow::promptForIncome()
{
    auto income = promptNewItem("Nova receita");
    ui->entryWidget->getList().addIncome(income);
}

void MainWindow::promptForExpense()
{
    auto expense = promptNewItem("Nova despesa");
    ui->entryWidget->getList().addExpense(expense);
}

Item MainWindow::promptNewItem(const QString& title)
{
    auto name  = QInputDialog::getText(this, title, "Nome do novo item:");
    auto category  = QInputDialog::getText(this, title,
                                           "Categoria do novo item:");
    auto value  = QInputDialog::getDouble(this, title,
                                        "Valor do novo item:");

    return Item(name, category, value);
}
