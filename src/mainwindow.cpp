#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(size());

    connect(ui->actionEditar, &QAction::triggered,
            ui->entryWidget, &EntryWidget::updateEntries);
}

MainWindow::~MainWindow()
{
    delete ui;
}
