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

    connect(ui->deleteButton, SIGNAL(clicked()),
            ui->entryWidget, SLOT(removeSelectedItem()));

    connect(ui->editButton, SIGNAL(clicked()),
            ui->entryWidget, SLOT(editSelectedItem()));

    auto signalMapper = new QSignalMapper(this);

    connect(ui->addIncomeAction, SIGNAL(triggered()),
            signalMapper, SLOT(map()));
    connect(ui->addExpenseAction, SIGNAL(triggered()),
            signalMapper, SLOT(map()));

    signalMapper->setMapping(ui->addIncomeAction, 0);
    signalMapper->setMapping(ui->addExpenseAction, 1);

    connect(signalMapper, SIGNAL(mapped(int)),
            ui->entryWidget, SLOT(addNewItem(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
