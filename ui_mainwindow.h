/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupSources;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QToolButton *addButton;
    QToolButton *deleteButton;
    QListWidget *listWidget;
    QPushButton *calculateButton;
    QGroupBox *groupResults;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *coincidenceCountLayout;
    QLabel *coincidenceCountLabel;
    QLabel *coincidenceCountOutput;
    QTableView *tableCoincidence;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1010, 299);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupSources = new QGroupBox(centralWidget);
        groupSources->setObjectName(QStringLiteral("groupSources"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupSources->sizePolicy().hasHeightForWidth());
        groupSources->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(groupSources);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit = new QLineEdit(groupSources);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        addButton = new QToolButton(groupSources);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout_2->addWidget(addButton);

        deleteButton = new QToolButton(groupSources);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        horizontalLayout_2->addWidget(deleteButton);


        verticalLayout->addLayout(horizontalLayout_2);

        listWidget = new QListWidget(groupSources);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);

        calculateButton = new QPushButton(groupSources);
        calculateButton->setObjectName(QStringLiteral("calculateButton"));

        verticalLayout->addWidget(calculateButton);


        horizontalLayout->addWidget(groupSources);

        groupResults = new QGroupBox(centralWidget);
        groupResults->setObjectName(QStringLiteral("groupResults"));
        sizePolicy.setHeightForWidth(groupResults->sizePolicy().hasHeightForWidth());
        groupResults->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(groupResults);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        coincidenceCountLayout = new QHBoxLayout();
        coincidenceCountLayout->setSpacing(6);
        coincidenceCountLayout->setObjectName(QStringLiteral("coincidenceCountLayout"));
        coincidenceCountLabel = new QLabel(groupResults);
        coincidenceCountLabel->setObjectName(QStringLiteral("coincidenceCountLabel"));

        coincidenceCountLayout->addWidget(coincidenceCountLabel);

        coincidenceCountOutput = new QLabel(groupResults);
        coincidenceCountOutput->setObjectName(QStringLiteral("coincidenceCountOutput"));

        coincidenceCountLayout->addWidget(coincidenceCountOutput);


        verticalLayout_2->addLayout(coincidenceCountLayout);

        tableCoincidence = new QTableView(groupResults);
        tableCoincidence->setObjectName(QStringLiteral("tableCoincidence"));
        tableCoincidence->setFrameShape(QFrame::StyledPanel);
        tableCoincidence->setFrameShadow(QFrame::Sunken);
        tableCoincidence->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableCoincidence->setTabKeyNavigation(true);
        tableCoincidence->setProperty("showDropIndicator", QVariant(false));
        tableCoincidence->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableCoincidence->setSortingEnabled(true);
        tableCoincidence->horizontalHeader()->setHighlightSections(false);
        tableCoincidence->horizontalHeader()->setStretchLastSection(true);
        tableCoincidence->verticalHeader()->setVisible(false);
        tableCoincidence->verticalHeader()->setHighlightSections(false);

        verticalLayout_2->addWidget(tableCoincidence);


        horizontalLayout->addWidget(groupResults);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\237\320\276\321\210\321\203\320\272 \320\260\320\261\321\226\321\202\321\203\321\200\321\226\321\224\320\275\321\202\321\226\320\262", 0));
        groupSources->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\321\201\320\270\320\273\320\260\320\275\320\275\321\217", 0));
        addButton->setText(QApplication::translate("MainWindow", "Add", 0));
        deleteButton->setText(QApplication::translate("MainWindow", "Clear list", 0));
        calculateButton->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\207\320\270\321\201\320\273\320\270\321\202\320\270", 0));
        groupResults->setTitle(QApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\320\270", 0));
        coincidenceCountLabel->setText(QApplication::translate("MainWindow", "\320\232\321\226\320\273\321\214\320\272\321\226\321\201\321\202\321\214 \320\267\320\261\321\226\320\263\321\226\320\262", 0));
        coincidenceCountOutput->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
