#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QMessageBox>
#include <QCloseEvent>
#include <QDebug>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    void closeEvent(QCloseEvent *event);
 signals:
     void goToSignUp();
     void closeLogin();
     void tryLogin(QString, QString);
private slots:
     void slotVerification(bool);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
