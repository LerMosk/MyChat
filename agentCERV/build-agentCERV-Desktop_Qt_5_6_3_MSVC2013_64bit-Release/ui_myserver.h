/********************************************************************************
** Form generated from reading UI file 'myserver.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYSERVER_H
#define UI_MYSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyServer
{
public:
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyServer)
    {
        if (MyServer->objectName().isEmpty())
            MyServer->setObjectName(QStringLiteral("MyServer"));
        MyServer->resize(400, 300);
        centralWidget = new QWidget(MyServer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(40, 20, 251, 201));
        MyServer->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MyServer);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        MyServer->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyServer);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MyServer->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MyServer);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyServer->setStatusBar(statusBar);

        retranslateUi(MyServer);

        QMetaObject::connectSlotsByName(MyServer);
    } // setupUi

    void retranslateUi(QMainWindow *MyServer)
    {
        MyServer->setWindowTitle(QApplication::translate("MyServer", "MyServer", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyServer: public Ui_MyServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYSERVER_H
