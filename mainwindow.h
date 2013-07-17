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

    void on_addButton_clicked();
    void on_deleteButton_clicked();

    void on_calculateButton_clicked();

private:
    Ui::MainWindow *ui;
    Controller controller;
};

#endif // MAINWINDOW_H
