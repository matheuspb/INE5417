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

void StatsWindow::showTotals(const double& totalIncome,
                             const double& totalExpenses,
                             const QHash<QString, double> totalCategories,
                             const QString month)
{
    QString output = "Estatísticas do mês " + month + "\n\n";

    output += ("Total de receitas = " + QString::number(totalIncome, 'f', 2) +"\n" +
               "Total de despesas = " + QString::number(totalExpenses, 'f', 2) + "\n");

    for (auto category: totalCategories) {
        output += ("\nTotal gasto com " + totalCategories.key(category) + " = " +
                QString::number(category, 'f', 2) + "(" +
                QString::number((category*100)/totalExpenses, 'f', 1) +
                "%)" + "\n");
    }

    output += "\n\n Saldo = " +
            QString::number(totalIncome - totalExpenses, 'f', 2);

    ui->label->setText(output);
}
