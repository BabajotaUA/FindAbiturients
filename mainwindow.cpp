#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    controller.showResults();
    ui->tableCoincidence->setModel(controller.getModel());
    ui->coincidenceCountOutput->setText(controller.showCoincidenceCount());
}
