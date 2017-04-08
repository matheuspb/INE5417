#include <QInputDialog>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

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
    ui->entryWidget->getList().removeItem(getSelected());
}

void MainWindow::on_editButton_clicked()
{
    auto old = getSelected();
    auto edited = promptNewItem("Editar item", old.type(), old);
    ui->entryWidget->getList().updateItem(old, edited);
}

void MainWindow::promptForIncome()
{
    auto income = promptNewItem("Nova receita", Item::income);
    ui->entryWidget->getList().addItem(income);
}

void MainWindow::promptForExpense()
{
    auto expense = promptNewItem("Nova despesa", Item::expense);
    ui->entryWidget->getList().addItem(expense);
}

Item MainWindow::getSelected() const
{
    auto selected = ui->entryWidget->selectedItems();
    auto type = static_cast<Item::Type>(selected[0]->type());
    return Item(selected[0]->text(0), selected[0]->text(1),
            selected[0]->text(2).toDouble(), type);
}

Item MainWindow::promptNewItem(const QString& title, const Item::Type& type,
                               const Item& hint)
{
    auto name = QInputDialog::getText(this, title, "Nome do item:",
                                      QLineEdit::Normal, hint.name());

    auto category = QInputDialog::getText(this, title, "Categoria do item:",
                                          QLineEdit::Normal, hint.category());

    auto value = QInputDialog::getDouble(this, title, "Valor do item:",
                                         QLineEdit::Normal, hint.value());

    return Item(name, category, value, type);
}
