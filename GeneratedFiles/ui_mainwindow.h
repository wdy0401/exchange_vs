/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *textline_4;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *ok_button_3;
    QPushButton *pushButton_2;
    QPushButton *cancel_button_4;
    QPushButton *pushButton;
    QTextEdit *textEdit_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *textline;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *ok_button;
    QPushButton *cancel_button;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QLineEdit *textline_3;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *ok_button_del;
    QPushButton *cancel_button_3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_2;
    QLineEdit *textline_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *ok_button_2;
    QPushButton *cancel_button_2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(779, 615);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 220, 721, 221));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 322, 191));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);


        verticalLayout_2->addLayout(horizontalLayout_4);

        textline_4 = new QLineEdit(verticalLayoutWidget);
        textline_4->setObjectName(QStringLiteral("textline_4"));
        textline_4->setMinimumSize(QSize(133, 0));

        verticalLayout_2->addWidget(textline_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        ok_button_3 = new QPushButton(verticalLayoutWidget);
        ok_button_3->setObjectName(QStringLiteral("ok_button_3"));

        horizontalLayout_3->addWidget(ok_button_3);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);

        cancel_button_4 = new QPushButton(verticalLayoutWidget);
        cancel_button_4->setObjectName(QStringLiteral("cancel_button_4"));

        horizontalLayout_3->addWidget(cancel_button_4);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout_3);

        textEdit_2 = new QTextEdit(verticalLayoutWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));

        verticalLayout_2->addWidget(textEdit_2);

        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(420, 0, 311, 191));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label, 0, Qt::AlignHCenter);

        textline = new QLineEdit(verticalLayoutWidget_2);
        textline->setObjectName(QStringLiteral("textline"));

        horizontalLayout->addWidget(textline, 0, Qt::AlignHCenter);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        ok_button = new QPushButton(verticalLayoutWidget_2);
        ok_button->setObjectName(QStringLiteral("ok_button"));

        horizontalLayout_2->addWidget(ok_button);

        cancel_button = new QPushButton(verticalLayoutWidget_2);
        cancel_button->setObjectName(QStringLiteral("cancel_button"));

        horizontalLayout_2->addWidget(cancel_button);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_6->addWidget(label_3, 0, Qt::AlignHCenter);

        textline_3 = new QLineEdit(verticalLayoutWidget_2);
        textline_3->setObjectName(QStringLiteral("textline_3"));

        horizontalLayout_6->addWidget(textline_3, 0, Qt::AlignRight);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        ok_button_del = new QPushButton(verticalLayoutWidget_2);
        ok_button_del->setObjectName(QStringLiteral("ok_button_del"));

        horizontalLayout_7->addWidget(ok_button_del);

        cancel_button_3 = new QPushButton(verticalLayoutWidget_2);
        cancel_button_3->setObjectName(QStringLiteral("cancel_button_3"));

        horizontalLayout_7->addWidget(cancel_button_3);


        verticalLayout_3->addLayout(horizontalLayout_7);


        verticalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_8->addWidget(label_2);

        textline_2 = new QLineEdit(verticalLayoutWidget_2);
        textline_2->setObjectName(QStringLiteral("textline_2"));
        textline_2->setMinimumSize(QSize(133, 0));

        horizontalLayout_8->addWidget(textline_2, 0, Qt::AlignHCenter);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        ok_button_2 = new QPushButton(verticalLayoutWidget_2);
        ok_button_2->setObjectName(QStringLiteral("ok_button_2"));

        horizontalLayout_5->addWidget(ok_button_2);

        cancel_button_2 = new QPushButton(verticalLayoutWidget_2);
        cancel_button_2->setObjectName(QStringLiteral("cancel_button_2"));

        horizontalLayout_5->addWidget(cancel_button_2);


        verticalLayout_5->addLayout(horizontalLayout_5);


        verticalLayout_4->addLayout(verticalLayout_5);

        verticalLayoutWidget_3 = new QWidget(centralWidget);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 450, 721, 80));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(verticalLayoutWidget_3);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_6->addWidget(label_5, 0, Qt::AlignHCenter);

        pushButton_3 = new QPushButton(verticalLayoutWidget_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_6->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(verticalLayoutWidget_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout_6->addWidget(pushButton_4);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 779, 23));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);
        QObject::connect(textline, SIGNAL(returnPressed()), ok_button, SLOT(click()));
        QObject::connect(textline_2, SIGNAL(returnPressed()), ok_button_2, SLOT(click()));
        QObject::connect(textline_4, SIGNAL(returnPressed()), ok_button_3, SLOT(click()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "add feed file", 0));
        ok_button_3->setText(QApplication::translate("MainWindow", "Add", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Cancel", 0));
        cancel_button_4->setText(QApplication::translate("MainWindow", "Delete", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Run", 0));
        label->setText(QApplication::translate("MainWindow", "generate file", 0));
        ok_button->setText(QApplication::translate("MainWindow", "Ok", 0));
        cancel_button->setText(QApplication::translate("MainWindow", "Cancel", 0));
        label_3->setText(QApplication::translate("MainWindow", "delete file", 0));
        ok_button_del->setText(QApplication::translate("MainWindow", "Ok", 0));
        cancel_button_3->setText(QApplication::translate("MainWindow", "Cancel", 0));
        label_2->setText(QApplication::translate("MainWindow", "     display file", 0));
        ok_button_2->setText(QApplication::translate("MainWindow", "Ok", 0));
        cancel_button_2->setText(QApplication::translate("MainWindow", "Cancel", 0));
        label_5->setText(QApplication::translate("MainWindow", "test label for vs2010sp1", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "test utf8 gbk", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
