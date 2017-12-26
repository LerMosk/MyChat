#include "myserver.h"
#include "ui_myserver.h"

MyServer::MyServer(int nPort, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyServer),
    NextBlockSize(0)
{
    ui->setupUi(this);
    QFile count("dial_count.bin");
    if(count.exists()&&count.open(QIODevice::ReadOnly))
    {
   QDataStream stream(&count);
   stream.setVersion(QDataStream::Qt_5_3);
   stream>>count_dial;
   count.close();
    }
   else count_dial=0;
    tcp_serv= new QTcpServer(this);
    if (!(tcp_serv->listen(QHostAddress::Any, nPort)))
    {QMessageBox::critical(0,"Server Error",
                           "Unable to start the server: "
                           +tcp_serv->errorString());
   tcp_serv->close();
   return;
    }
    connect (tcp_serv, SIGNAL(newConnection()), this, SLOT(slotNewConnection()));

}

void MyServer::slotNewConnection()
{
QTcpSocket * Socket=tcp_serv->nextPendingConnection();  //возвр сокет, с помощью кот можно осущ связь с клиентом
connect(Socket, SIGNAL(readyRead()), this, SLOT(slotReadClient()));
}
void MyServer::slotClientDisconnected()
{
    QTcpSocket* Socket = (QTcpSocket*)sender(); 
    QList<QString> kl=SClients.keys(Socket);
    QString name=kl.takeFirst();
       SClients[name]->deleteLater();
       SClients.remove(name);
        ClientsKeys.remove(name);
       foreach(QString i,SClients.keys())
           sendToClient(SClients[i],3, name );
}

void MyServer::slotReadClient()
{
    qDebug()<<"read";
    QTcpSocket* Socket = (QTcpSocket*)sender();
QDataStream in(Socket);
in.setVersion(QDataStream::Qt_5_3);
for (;;)
{if(!NextBlockSize)
    {
        if(Socket->bytesAvailable()<sizeof(qint16)) break;

        in>>NextBlockSize;

    }
     qDebug()<<Socket->bytesAvailable();
      if(Socket->bytesAvailable()>=NextBlockSize) break;
}
qDebug()<<NextBlockSize;
NextBlockSize=0;
qint8 command;
in>>command;
switch (command) {
case 1:                         //имя серверу(на проверку уникальности)
{
    qDebug()<<"case 1";
    QString name, password;
    int openkey;
    in>>name>>password>>openkey;
    AvailibleName(Socket, name,password, openkey);
    break;}
case 2:                           //сообщение клиенту
{qDebug()<<"case 2";
    QString to_name, from_name, sentmes, dt;
    QVector<QPair<int, int> > msg, my_msg;
    in>>to_name>>dt>>from_name>>msg>>my_msg;
    sentmes=dt+": "+from_name+": ";
    addToHistory(to_name, from_name, sentmes, msg);
    addToHistory(from_name, to_name, sentmes, my_msg);
    sendToClientMesg(SClients[to_name],from_name,sentmes, msg);
    break;}
  case 3:      //try login
{
    qDebug()<<"case 3";
    QString name, password;
    in>>name>>password;
    Verification(Socket, name,password);
    break;
}
case 4:      //clean history
{
  qDebug()<<"case 4";
  QString name, name_clean;
  in>>name>>name_clean;
cleanDialog(name, name_clean);
  break;
}
case 5:      //client exit
{
  qDebug()<<"case 5";
  QString name;
  in>>name;
ClientsKeys.remove(name);
disconnect(SClients[name], SIGNAL(disconnected()),this , SLOT(slotClientDisconnected()));
SClients.remove(name);
if(SClients.count()!=0)
foreach(QString i,SClients.keys())
    sendToClient(SClients[i],3, name );
  break;
}
case 6:      //client delete account
{
  qDebug()<<"case 6";
  QString name;
  in>>name;
deleteAccount(name);
  break;
}
case 7:      //send file
{
  while(fileData.size()!=0)
  {}
  disconnect(Socket, SIGNAL(readyRead()), this, SLOT(slotReadClient()));
  connect(Socket, SIGNAL(readyRead()), this, SLOT(slotReadFile()));
  qDebug()<<"case 7";
  in>>fileTo>>fileName>>fileSize;
  qDebug()<<fileTo;
  qDebug()<<fileName;
  qDebug()<<fileSize;
  QList<QString> kl=SClients.keys(Socket);
 fileFrom=kl.takeFirst();

  break;
}
case 8:      // file answer
{
  qDebug()<<"case 8";
  QString fromF, nameF;
  qint8 ans;
  in>>ans>>fromF>>nameF;
  if(ans==1) sendToClientFile(Socket,fromF, nameF);
  else
  {
      QFile file("Downloads/"+fromF+"/"+nameF);
      file.remove();
  }
  break;
}
}

}

void MyServer::sendAllHistory(QTcpSocket* pSocket, const QString & name)
{
    QFile dialogs("dialogs.bin");
    if(dialogs.exists()&& dialogs.open(QIODevice::ReadOnly))
    {
   QDataStream stream(&dialogs);
   stream.setVersion(QDataStream::Qt_5_3);
   while(!stream.atEnd())
   {
    QString name1, name2, numb;
   stream>>numb>>name1>>name2;
   if (name1==name) sendHistory(pSocket, name2, numb);
   }
    }
    dialogs.close();

}

void MyServer::Verification(QTcpSocket* pSocket, const QString & name1,const QString & password1)
{
    qDebug()<<"vertfication";
    bool  flag=true;
    QFile logins("Logins.bin");
    if(logins.open(QIODevice::ReadOnly))
    {
   QDataStream stream(&logins);
   stream.setVersion(QDataStream::Qt_5_3);
   while(!stream.atEnd())
   {
     QString name2, password2;
     int openkey;
   stream>>name2>>password2>>openkey;
   if(name1==name2)
   {
       flag=false;
       if ((password1==password2)&&(openkey!=0))
       {
           sendToClientOpenkey(pSocket, 5, name1, openkey);
           SClients[name1]=pSocket;
            ClientsKeys[name1]=openkey;
            if(SClients.count()!=1)
            foreach(QString namecl,SClients.keys())
                if(namecl!=name1) sendToClientOpenkey(SClients[namecl],2, name1, openkey );
            connect(SClients[name1], SIGNAL(disconnected()),this , SLOT(slotClientDisconnected()));
            if(SClients.count()!=1)
            {
                QMap<QString,int> ClKeys(ClientsKeys);
                ClKeys.remove(name1);
            sendToClientAllClients(SClients[name1], ClKeys);
            }
            sendAllHistory(pSocket, name1);
       }
       else sendToClient(pSocket, 5, "No");
   }
   }
    }
   logins.close();
   if (flag==true) sendToClient(pSocket, 5, "No");

}

void MyServer::sendHistory(QTcpSocket *pSocket, const QString & name , const QString & dial)
{
    QVector <QPair<QString, QVector<QPair<int, int> > > > vect;
    QFile history(dial+".bin");
    if(history.open(QIODevice::ReadOnly))
    {
        QDataStream stream(&history);
        stream.setVersion(QDataStream::Qt_5_3);
        while(!stream.atEnd())
        {
            QVector<QPair<int, int> > v;
            QString str;
            stream>>str>>v;
            vect.push_back(qMakePair(str, v));
        }
    }
    history.close();
  QByteArray arrBlock;
  QDataStream out(&arrBlock, QIODevice::WriteOnly);
  out.setVersion(QDataStream::Qt_5_3);
  out<<quint16(0)<<qint8(7)<<name<<vect;
  out.device()->seek(0);
  out<<quint16(arrBlock.size()-sizeof(qint16));
  pSocket->write(arrBlock);
  qDebug()<<"sendHistory";

}

void MyServer::addToHistory(const QString & name_crypt, const QString & dial_with,const QString & msg, const QVector<QPair<int, int> > & crypt)
{
    qDebug()<<"addToHistory "<<name_crypt;
    QString dial_numb=" ";
    QFile dialogs("dialogs.bin");
    if(dialogs.exists()&& dialogs.open(QIODevice::ReadOnly))
    {
        qDebug()<<"dialogs.exists";
   QDataStream stream(&dialogs);
   stream.setVersion(QDataStream::Qt_5_3);
   while(!stream.atEnd())
   {
    QString name1, name2, numb;
   stream>>numb>>name1>>name2;
   qDebug()<<numb<<" "<<name1<<" "<<name2;
   if ((name1==name_crypt)&&(name2==dial_with))
     dial_numb=numb;
   }
    }
    dialogs.close();
   if((dial_numb==" ") && dialogs.open(QIODevice::Append | QIODevice::Text))
       {
      dial_numb=QString::number(++count_dial);
      QDataStream stream(&dialogs);
      stream.setVersion(QDataStream::Qt_5_3);
      stream<<dial_numb<<name_crypt<<dial_with;
       }
   dialogs.close();
    QFile history(dial_numb+".bin");
    if(history.open(QIODevice::Append | QIODevice::Text))
    {
        QDataStream stream(&history);
        stream.setVersion(QDataStream::Qt_5_3);
        stream<<msg<<crypt;
    }
    history.close();
}

void MyServer::deleteAccount(const QString &name)
{
    ClientsKeys.remove(name);
    disconnect(SClients[name], SIGNAL(disconnected()),this , SLOT(slotClientDisconnected()));
    SClients.remove(name);
    if(SClients.count()!=0)
    foreach(QString i,SClients.keys())
        sendToClient(SClients[i],3, name );

    QStringList dial_numbs;
    QFile dialogs("dialogs.bin");
     QFile dialogs2("dialogs2.bin");
    if( dialogs.open(QIODevice::ReadOnly)&&dialogs2.open(QIODevice::Append | QIODevice::Text))
    {
   QDataStream stream(&dialogs);
   QDataStream stream2(&dialogs2);
   stream.setVersion(QDataStream::Qt_5_3);
   while(!stream.atEnd())
   {
    QString name1, name2, numb;
   stream>>numb>>name1>>name2;
   if (name==name1)
     dial_numbs<<numb;
   else stream2<<numb<<name1<<name2;
   }
    }
    dialogs.close();
    dialogs2.close();
    qDebug()<<dialogs.remove();
    qDebug()<<dialogs2.rename("dialogs.bin");

    foreach (QString str, dial_numbs )
  QFile::remove(str+".bin");

    QFile logins("logins.bin");
     QFile logins2("logins2.bin");
    if( logins.open(QIODevice::ReadOnly)&&logins2.open(QIODevice::Append | QIODevice::Text))
    {
   QDataStream stream(&logins);
   QDataStream stream2(&logins2);
   stream.setVersion(QDataStream::Qt_5_3);
   while(!stream.atEnd())
   {
    QString namecl, password;
    int openkey;
   stream>>namecl>>password>>openkey;
   if (name==namecl) openkey=0;
 stream2<<namecl<<password<<openkey;
   }
    }
    logins.close();
    logins2.close();
    qDebug()<<logins.remove();
    qDebug()<<logins2.rename("logins.bin");

}

void MyServer::cleanDialog(const QString & name11, const QString & name22)
{
    qDebug()<<"cleanDialog";
    QString dial_numb;
    QFile dialogs("dialogs.bin");
     QFile dialogs2("dialogs2.bin");
    if( dialogs.open(QIODevice::ReadOnly)&&dialogs2.open(QIODevice::Append | QIODevice::Text))
    {
   QDataStream stream(&dialogs);
   QDataStream stream2(&dialogs2);
   stream.setVersion(QDataStream::Qt_5_3);
   while(!stream.atEnd())
   {
    QString name1, name2, numb;
   stream>>numb>>name1>>name2;
   if ((name1==name11)&&(name2==name22))
     dial_numb=numb;
   else stream2<<numb<<name1<<name2;
   }
    }
    dialogs.close();
    qDebug()<<dialogs.remove();
    dialogs2.close();
    qDebug()<<dialogs2.rename("dialogs.bin");
    QFile::remove(dial_numb+".bin");
}

void MyServer::AvailibleName( QTcpSocket* pSocket, const QString & name,const QString & password, const int& openkey)
{bool flag=true;
    QFile logins("Logins.bin");
    if(logins.open(QIODevice::ReadOnly))
    {
   QDataStream stream(&logins);
   stream.setVersion(QDataStream::Qt_5_3);
   while(!stream.atEnd())
   {
     QString name2, password2;
     int openkey;
   stream>>name2>>password2>>openkey;
       if(name2==name) {sendToClient(pSocket,6,"No");
           flag=false;
       break;}
   }
    }
    logins.close();
   if(flag==true)
   { 
       QFile logins("Logins.bin");
       if(logins.open(QIODevice::Append | QIODevice::Text))
       {
      QDataStream stream(&logins);
      stream.setVersion(QDataStream::Qt_5_3);
      stream<<name<<password<<openkey;
      logins.close();
       }
       SClients[name]=pSocket;
       sendToClient(pSocket,6,name);
        ClientsKeys[name]=openkey;
        if(SClients.count()!=1)
        foreach(QString namecl,SClients.keys())
            if(namecl!=name) sendToClientOpenkey(SClients[namecl], 2,name, openkey );
        connect(SClients[name], SIGNAL(disconnected()),this , SLOT(slotClientDisconnected()));
        if(SClients.count()!=1)
        {
            QMap<QString,int> ClKeys(ClientsKeys);
            ClKeys.remove(name);
        sendToClientAllClients(SClients[name], ClKeys);
        }
   }
}
 void MyServer::sendToClientOpenkey(QTcpSocket* pSocket,const qint8 & command, const QString & msg, const int & openkey )
{
   QByteArray arrBlock;
   QDataStream out(&arrBlock, QIODevice::WriteOnly);
   out.setVersion(QDataStream::Qt_5_3);
   out<<quint16(0)<<command<<msg<<openkey;
   out.device()->seek(0);
   out<<quint16(arrBlock.size()-sizeof(qint16));
   pSocket->write(arrBlock);
qDebug()<<"sendToClientOpenkey";
 }
 void MyServer::sendToClient(QTcpSocket* pSocket,const qint8 & command, const QString & msg)
{
   QByteArray arrBlock;
   QDataStream out(&arrBlock, QIODevice::WriteOnly);
   out.setVersion(QDataStream::Qt_5_3);
   out<<quint16(0)<<command<<msg;
   out.device()->seek(0);
   qDebug()<<arrBlock.size()-sizeof(qint16);
   out<<quint16(arrBlock.size()-sizeof(qint16));
   pSocket->write(arrBlock);
   qDebug()<<"sendToClient";
 }
 void MyServer::slotReadFile()
 {
     qDebug()<<"slotreadfile";
     QTcpSocket* Socket = (QTcpSocket*)sender();
     qDebug()<<Socket->bytesAvailable();
     QByteArray arr=Socket->readAll();
      qDebug()<<arr.size();
     fileData.push_back(arr);
     qDebug()<<"file data: "<<fileData.size();
    if(fileData.size()>=fileSize)
    {
        qDebug()<<fileData.size();
        qDebug()<<"File send OK";
        disconnect(Socket, SIGNAL(readyRead()), this, SLOT(slotReadFile()));
     connect(Socket, SIGNAL(readyRead()), this, SLOT(slotReadClient()));
      QString savePath = "Downloads/"+fileFrom+"/";
      QDir dir;
      dir.mkpath(savePath);
      QFile receiveFile (savePath + fileName);
    if(receiveFile.open(QIODevice::WriteOnly))
      receiveFile.write(fileData);
     receiveFile.close();
     fileData.clear();
     sendToClientFileInfo();
    }

 }

 void MyServer::sendToClientFileInfo()    //send file
 {
    qDebug()<<"sendToClientFile";
   QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_3);
    out<<quint16(0)<<qint8(8)<<fileFrom<<fileName<<fileSize;
    out.device()->seek(0);
    qDebug()<<arrBlock.size()-sizeof(qint16);
    out<<quint16(arrBlock.size()-sizeof(qint16));
    qDebug()<<"sendToClientFile1";
    SClients[fileTo]->write(arrBlock);

 }
  void MyServer::sendToClientFile(QTcpSocket* pSocket,const QString & fromF, const QString & nameF)
  {
      QFile file("Downloads/"+fromF+"/"+nameF);
      QByteArray arr;
      if(file.open(QIODevice::ReadOnly))
          arr=file.readAll();
      file.close();
      file.remove();
      pSocket->write(arr);
         qDebug()<<"sendToClientFile2";
  }

 void MyServer::sendToClientMesg(QTcpSocket* pSocket,const QString &msg_from,const QString & msg, const QVector<QPair<int, int> > & v)
{

   QByteArray arrBlock;
   QDataStream out(&arrBlock, QIODevice::WriteOnly);
   out.setVersion(QDataStream::Qt_5_3);
   out<<quint16(0)<<qint8(1)<<msg_from<<msg<<v;
   out.device()->seek(0);
   out<<quint16(arrBlock.size()-sizeof(qint16));
   pSocket->write(arrBlock);
   qDebug()<<"sendToClientMesg";

 }
void MyServer::sendToClientAllClients(QTcpSocket* pSocket,QMap<QString,int> & ClKeys )
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_3);
    out<<quint16(0)<<qint8(4)<<ClKeys;
    out.device()->seek(0);
    out<<quint16(arrBlock.size()-sizeof(qint16));
  pSocket->write(arrBlock);
   qDebug()<<"sendToClientAllClients";
}

MyServer::~MyServer()
{
    delete ui;
}

void MyServer::closeEvent(QCloseEvent *event)
{
    QFile count("dial_count.bin");
    if(count.open(QIODevice::Append | QIODevice::Text | QIODevice::Truncate))
    {
   QDataStream stream(&count);
   stream.setVersion(QDataStream::Qt_5_3);
   stream<<count_dial;
  count.close();
    }
}
