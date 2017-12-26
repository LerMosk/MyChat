#include "signup.h"
#include "ui_signup.h"

SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);
}
void SignUp::slotChecked(bool checked)   //ответ от сервера о доступности ника
{
   if(checked==true)
   {
       this->destroy();
   }
   else    { QMessageBox msgBox;
       msgBox.setText("Этот логин занят.");
       msgBox.exec();}
}


void SignUp::on_pushButton_clicked()    //signUp
{
    if((ui->lineEdit->text().size()>15)||(ui->lineEdit_2->text().size()>15)||(ui->lineEdit_3->text().size()>15))
    {
        QMessageBox msgBox;
               msgBox.setText("Слишком большой логин или пароль. Максимальная длина 15 символов.");
               msgBox.exec();
               return;
    }
   if(!ui->lineEdit_2->text().compare(" ")||!ui->lineEdit->text().compare(" ")||ui->lineEdit->text().isEmpty()||ui->lineEdit_2->text().isEmpty())
       { ui->label_2->setText("Вы не ввели логин или пароль");
  return;
    }
    if(ui->lineEdit_2->text()!=ui->lineEdit_3->text())
    { ui->label_2->setText("Пароли не совпадают.");
        return;}
    if(ui->lineEdit_2->text().size()<3)
    { ui->label_2->setText("Слишком маленький пароль");
        return;}
        emit trySignUp(ui->lineEdit->text(), ui->lineEdit_2->text());
}

void SignUp::closeEvent(QCloseEvent *event)  // show prompt when user wants to close app
{
     emit closeSignUp();
       event->accept();
}

void SignUp::on_pushButton_2_clicked()    //перейти к входу
{
this->close();
    emit goToLogin();
    this->destroy();
}
SignUp::~SignUp()
{
    delete ui;
}
