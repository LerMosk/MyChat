
#ifndef MYSERVER_H
#define MYSERVER_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>
#include <QString>
#include <QTime>
#include <QMap>
#include <QFile>
#include <QByteArray>
#include <QAbstractSocket>
#include <QDataStream>
#include <QHostAddress>
#include <QMessageBox>
#include <QVector>
#include <QPair>
#include<QtDebug>
#include <QDir>
namespace Ui {
class MyServer;
}

class MyServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyServer(int nPort, QWidget *parent = 0);
    ~MyServer();
    void closeEvent(QCloseEvent *event);
private:
void  sendToClient(QTcpSocket* pSocket,const qint8 & command, const QString & msg);
void sendToClientFileInfo();
void sendToClientFile(QTcpSocket* pSocket,const QString &, const QString &);
void sendToClientOpenkey(QTcpSocket* pSocket,const qint8 & command, const QString & msg, const int & openkey );
     void sendToClientAllClients(QTcpSocket* pSocket,QMap<QString,int>& );
     void sendToClientMesg(QTcpSocket* pSocket,const QString &msg_from, const QString & msg, const QVector<QPair<int, int> > &);
void AvailibleName(QTcpSocket* pSocket, const QString &,const QString &, const int&);
void Verification(QTcpSocket* pSocket, const QString &,const QString &);
void sendAllHistory(QTcpSocket* pSocket, const QString &);
void sendHistory(QTcpSocket* pSocket, const QString &, const QString &);
void addToHistory(const QString &, const QString &,const QString &,const QVector<QPair<int, int> > & );
void deleteAccount(const QString & name);
void cleanDialog(const QString &, const QString &);
public slots:
    virtual void slotNewConnection();
    void slotReadClient();
    void slotReadFile();
    void slotClientDisconnected();
private:
    Ui::MyServer *ui;
    QTcpServer* tcp_serv;
   quint16 NextBlockSize;
QMap<QString,int> ClientsKeys;
QMap<QString,QTcpSocket *> SClients;
int count_dial;
QByteArray fileData;
int fileSize;
QString fileName;
QString fileFrom;
QString fileTo;
};

#endif // MYSERVER_H
