#include <stats-window.h>
#include <ui_statswindow.h>

StatsWindow::StatsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StatsWindow)
{
    ui->setupUi(this);
}

StatsWindow::~StatsWindow()
{
    delete ui;
}

void StatsWindow::setItemsToShow(const QList<Item>& items, const QString month)
{
    QString output = "Estatísticas do mês " + month + "\n\n";

    double incomes = 0, expenses = 0;

    for (auto item: items) {
        if (item.type() == Item::Type::income) {
            incomes += item.value();
        } else {
            expenses += item.value();
        }
    }

    output += ("Total de receitas = " + QString::number(incomes, 'f', 2) + "\n"
              + "Total de despesas = " + QString::number(expenses, 'f', 2));

    output += "\n\n Saldo = " + QString::number(incomes - expenses, 'f', 2);

    ui->label->setText(output);
}
