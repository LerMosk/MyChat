
#ifndef MYCLIENT_H
#define MYCLIENT_H
#include<QtDebug>
#include <QMainWindow>
#include <QTcpSocket>
#include <QString>
#include <QStringList>
#include <QTime>
#include <QDateTime>
#include <QMap>
#include <QByteArray>
#include <QAbstractSocket>
#include <QDataStream>
#include <QListWidgetItem>
#include <QTabWidget>
#include <QTextEdit>
#include <QCloseEvent>
#include <ctime>
#include <QVector>
#include<QFileDialog>
#include <QPair>
#include <QSound>
#include <string>
#include "signup.h"
#include "login.h"
using namespace std;
namespace Ui {
class MyClient;
}

class MyClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyClient(const QString& strHost, int nPort, QWidget *parent = 0);
    ~MyClient();
void closeEvent(QCloseEvent *event);
void displayMessage(QString &, QString &,QVector<QPair<int, int> >& );
private slots:
    void slotReadyRead();
      void slotReadFile();
    void slotTrySignUp(const QString &,const QString & );
     void slotTryLogin(const QString &,const QString & );
   void  ShowContextMenu(const QPoint&);
void slotError(QAbstractSocket::SocketError);
void slotSendToServer();
void on_listWidget_itemClicked(QListWidgetItem *item);
void slotCloseMain();
void on_tabWidget_tabCloseRequested(int index);
void slotOpenLogin();
void slotOpenSignUp();
void slotChangeUser();
void slotDeleteAccount();
void slotSendFile();

signals:
void Checked(bool);
void Verification(bool);
void MyCallRead();
void goToLogin();
private:
    Ui::MyClient *ui;
    QTcpSocket * Socket;
     quint16 NextBlockSize;
     int closekey;
     int openkey;
     QString name;
     QFile file;
     QMap<QString,QListWidgetItem * > list;
     QMap<QString,int> tabs;
     QMap<QString,QTextEdit * > dialogs;
     QMap<QString,int> open_keys;
     int fileSize;
     QString fileName;
     QByteArray fileData;
};
#endif // MYCLIENT_H
