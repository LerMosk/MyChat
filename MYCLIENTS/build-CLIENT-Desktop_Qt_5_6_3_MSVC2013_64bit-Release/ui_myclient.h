/********************************************************************************
** Form generated from reading UI file 'myclient.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCLIENT_H
#define UI_MYCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyClient
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTabWidget *tabWidget;
    QListWidget *listWidget;
    QTextEdit *textEdit_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyClient)
    {
        if (MyClient->objectName().isEmpty())
            MyClient->setObjectName(QStringLiteral("MyClient"));
        MyClient->resize(433, 320);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(7);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MyClient->sizePolicy().hasHeightForWidth());
        MyClient->setSizePolicy(sizePolicy);
        MyClient->setMinimumSize(QSize(433, 320));
        MyClient->setMaximumSize(QSize(433, 320));
        QIcon icon;
        QString iconThemeName = QStringLiteral("golub");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral(":/images/dove2.png"), QSize(), QIcon::Normal, QIcon::Off);
        }
        MyClient->setWindowIcon(icon);
        MyClient->setStyleSheet(QLatin1String("\n"
"background-color: rgb(235, 255, 254);"));
        centralWidget = new QWidget(MyClient);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(330, 210, 51, 51));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMinimumSize(QSize(30, 30));
        pushButton->setStyleSheet(QLatin1String(" border-style: outset;\n"
"background-color: rgb(255, 255, 255);\n"
"     border-width: 2px;\n"
"border-color: rgb(60, 103, 172);\n"
"border-radius: 10px;"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(380, 210, 51, 51));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setMinimumSize(QSize(30, 30));
        pushButton_2->setStyleSheet(QLatin1String(" border-style: outset;\n"
"background-color: rgb(255, 255, 255);\n"
"     border-width: 2px;\n"
"border-color: rgb(60, 103, 172);\n"
"border-radius: 10px;"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 280, 209));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tabWidget->setStyleSheet(QLatin1String("\n"
"background-color: rgb(255, 255, 255);\n"
" border-style: outset;\n"
"     border-width: 2px;\n"
"border-color: rgb(60, 103, 172);\n"
"border-radius: 10px;\n"
"tab :\n"
"{\n"
"background-color: rgb(188, 247, 255);\n"
"}"));
        tabWidget->setTabsClosable(true);
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(280, 0, 151, 209));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Ignored);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy3);
        listWidget->setMinimumSize(QSize(0, 0));
        listWidget->setMaximumSize(QSize(159, 16777215));
        listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        listWidget->setStyleSheet(QLatin1String("	background-color: rgb(255, 255, 255);\n"
" border-style: outset;\n"
"     border-width: 2px;\n"
"border-color: rgb(60, 103, 172);\n"
"border-radius: 10px;\n"
""));
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(0, 210, 331, 51));
        textEdit_2->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
" border-style: outset;\n"
"     border-width: 2px;\n"
"border-color: rgb(60, 103, 172);\n"
"border-radius: 10px;"));
        MyClient->setCentralWidget(centralWidget);
        tabWidget->raise();
        listWidget->raise();
        textEdit_2->raise();
        pushButton_2->raise();
        pushButton->raise();
        menuBar = new QMenuBar(MyClient);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 433, 21));
        MyClient->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyClient);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MyClient->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MyClient);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyClient->setStatusBar(statusBar);

        retranslateUi(MyClient);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MyClient);
    } // setupUi

    void retranslateUi(QMainWindow *MyClient)
    {
        MyClient->setWindowTitle(QApplication::translate("MyClient", "\320\223\320\276\320\273\321\203\320\261\321\214", Q_NULLPTR));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MyClient: public Ui_MyClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCLIENT_H
