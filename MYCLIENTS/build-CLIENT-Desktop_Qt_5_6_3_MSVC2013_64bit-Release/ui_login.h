/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(439, 232);
        QPalette palette;
        QBrush brush(QColor(235, 255, 254, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        Login->setPalette(palette);
        QIcon icon;
        QString iconThemeName = QStringLiteral("golub");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral(":/images/dove2.png"), QSize(), QIcon::Normal, QIcon::Off);
        }
        Login->setWindowIcon(icon);
        Login->setStyleSheet(QLatin1String("background-color: rgb(235, 255, 254);\n"
" border-style: outset;\n"
"     border-width: 2px;\n"
"border-color: rgb(60, 103, 172);\n"
"border-radius: 10px;\n"
"\n"
""));
        pushButton = new QPushButton(Login);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(270, 200, 161, 21));
        pushButton->setStyleSheet(QLatin1String(" border-style: outset;\n"
"     border-width: 2px;\n"
"border-color: rgb(60, 103, 172);\n"
"border-radius: 10px;\n"
"background-color:rgb(255, 255, 255)"));
        lineEdit = new QLineEdit(Login);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(100, 30, 231, 31));
        lineEdit->setStyleSheet(QLatin1String(" border-style: outset;\n"
"     border-width: 2px;\n"
"border-color: rgb(60, 103, 172);\n"
"border-radius: 10px;\n"
"background-color:rgb(255, 255, 255)"));
        lineEdit_2 = new QLineEdit(Login);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(100, 80, 231, 31));
        lineEdit_2->setStyleSheet(QLatin1String(" border-style: outset;\n"
"     border-width: 2px;\n"
"border-color: rgb(60, 103, 172);\n"
"border-radius: 10px;\n"
"background-color:rgb(255, 255, 255)"));
        pushButton_2 = new QPushButton(Login);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(100, 140, 231, 41));
        QFont font;
        font.setPointSize(12);
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QLatin1String(" border-style: outset;\n"
"     border-width: 2px;\n"
"border-color: rgb(60, 103, 172);\n"
"border-radius: 10px;\n"
"background-color:rgb(255, 255, 255)"));
        label = new QLabel(Login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 30, 61, 21));
        label->setFont(font);
        label->setStyleSheet(QLatin1String(" border-style: non;\n"
""));
        label_2 = new QLabel(Login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 80, 71, 31));
        label_2->setFont(font);
        label_2->setStyleSheet(QLatin1String(" border-style: non;\n"
""));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "\320\222\321\205\320\276\320\264", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Login", "\320\243 \320\274\320\265\320\275\321\217 \320\275\320\265\321\202 \320\260\320\272\320\272\320\260\321\203\320\275\321\202\320\260", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Login", "\320\222\320\276\320\271\321\202\320\270", Q_NULLPTR));
        label->setText(QApplication::translate("Login", "\320\233\320\276\320\263\320\270\320\275", Q_NULLPTR));
        label_2->setText(QApplication::translate("Login", "\320\237\320\260\321\200\320\276\320\273\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
