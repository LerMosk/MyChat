/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

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

class Ui_SignUp
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *SignUp)
    {
        if (SignUp->objectName().isEmpty())
            SignUp->setObjectName(QStringLiteral("SignUp"));
        SignUp->resize(491, 297);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/dove2.png"), QSize(), QIcon::Normal, QIcon::Off);
        SignUp->setWindowIcon(icon);
        SignUp->setStyleSheet(QLatin1String(" border-style: outset;\n"
"     border-width: 2px;\n"
"border-color: rgb(60, 103, 172);\n"
"border-radius: 10px;\n"
"background-color: rgb(235, 255, 254);"));
        SignUp->setModal(true);
        lineEdit = new QLineEdit(SignUp);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(170, 20, 201, 31));
        lineEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(SignUp);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(170, 200, 201, 41));
        QFont font;
        font.setPointSize(12);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton_2 = new QPushButton(SignUp);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 250, 181, 21));
        QFont font1;
        font1.setPointSize(10);
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label = new QLabel(SignUp);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 20, 71, 31));
        label->setFont(font);
        label->setStyleSheet(QStringLiteral(" border-style: non;"));
        label_2 = new QLabel(SignUp);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 170, 141, 16));
        label_2->setStyleSheet(QStringLiteral(" border-style: non;"));
        lineEdit_2 = new QLineEdit(SignUp);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(170, 70, 201, 31));
        lineEdit_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lineEdit_3 = new QLineEdit(SignUp);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(170, 120, 201, 31));
        lineEdit_3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_3 = new QLabel(SignUp);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 70, 71, 31));
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral(" border-style: non;"));
        label_4 = new QLabel(SignUp);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 110, 151, 41));
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral(" border-style: non;"));

        retranslateUi(SignUp);

        QMetaObject::connectSlotsByName(SignUp);
    } // setupUi

    void retranslateUi(QDialog *SignUp)
    {
        SignUp->setWindowTitle(QApplication::translate("SignUp", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", Q_NULLPTR));
        pushButton->setText(QApplication::translate("SignUp", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("SignUp", "\320\243\320\266\320\265 \320\265\321\201\321\202\321\214 \320\260\320\272\320\272\320\260\321\203\320\275\321\202", Q_NULLPTR));
        label->setText(QApplication::translate("SignUp", "\320\233\320\276\320\263\320\270\320\275", Q_NULLPTR));
        label_2->setText(QString());
        label_3->setText(QApplication::translate("SignUp", "\320\237\320\260\321\200\320\276\320\273\321\214", Q_NULLPTR));
        label_4->setText(QApplication::translate("SignUp", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SignUp: public Ui_SignUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
