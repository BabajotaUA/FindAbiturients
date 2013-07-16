#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "controller.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_toolButton_clicked();
    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_listWidget_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    Controller controller;
};

#endif // MAINWINDOW_H
