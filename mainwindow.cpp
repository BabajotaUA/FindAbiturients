#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableCoincidence->setModel(controller.getModel());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    if (ui->lineEdit->text().isEmpty())
        return;

    controller.addNewSource(ui->lineEdit->text());

    ui->listWidget->addItem(ui->lineEdit->text());
    ui->lineEdit->clear();
}

void MainWindow::on_deleteButton_clicked()
{
    ui->listWidget->clear();
}

void MainWindow::on_calculateButton_clicked()
{
    ui->coincidenceCountOutput->setText(controller.showCoincidenceCount());
}
