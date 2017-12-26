#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

Login::~Login()
{
    delete ui;
}
void Login::on_pushButton_clicked()
{
    this->close();
    emit goToSignUp();
}
void Login::closeEvent(QCloseEvent *event)  // show prompt when user wants to close app
{
        emit closeLogin();
        event->accept();
        this->destroy();
}
void Login::slotVerification(bool answer)
{
    if(answer==true)
    {
        this->destroy();
    }
    else    { QMessageBox msgBox;
        msgBox.setText("Неверный логин или пароль.");
        msgBox.exec();}
}

void Login::on_pushButton_2_clicked()    //entry
{
    if((ui->lineEdit->text().size()>15)||(ui->lineEdit_2->text().size()>15))
    {
        QMessageBox msgBox;
               msgBox.setText("Слишком большой логин или пароль. Максимальная длина 15 символов.");
               msgBox.exec();
               return;
    }
   emit tryLogin(ui->lineEdit->text(),ui->lineEdit_2->text());
    qDebug()<<"try login";
}
