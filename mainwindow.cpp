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

void MainWindow::on_toolButton_clicked()
{
    if (ui->lineEdit->text().isEmpty())
        return;

    controller.addNewSource(ui->lineEdit->text());

    ui->listWidget->addItem(ui->lineEdit->text());
    ui->lineEdit->clear();
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{

}
void MainWindow::on_listWidget_clicked(const QModelIndex &index)
{
    ui->outputBox->setText(controller.showHtmlOutput(index.row()));
}
