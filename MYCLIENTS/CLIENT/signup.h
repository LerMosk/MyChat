#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <QMessageBox>
#include <QCloseEvent>
#include<QtDebug>
namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = 0);
    ~SignUp();

    void closeEvent(QCloseEvent *event);
    signals:
        void trySignUp(const QString &,const QString & );
        void closeSignUp();
        void goToLogin();
    private slots:

        void slotChecked(bool);
        void on_pushButton_clicked();
        void on_pushButton_2_clicked();

private:
    Ui::SignUp *ui;
};

#endif // SIGNUP_H
