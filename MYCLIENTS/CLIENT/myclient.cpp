
#include "myclient.h"
#include "ui_myclient.h"
int power(int a, int b, int n);
int mul(int a, int b, int n);
void crypt(int p, int g, int y, string in, QVector <QPair<int, int> > &mas);
void decrypt(int p, int x, QVector <QPair<int, int> > mas, string &out);
MyClient::MyClient(const QString& strHost, int nPort, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyClient), NextBlockSize(0)
{
    ui->setupUi(this);
    Socket=new QTcpSocket(this);
    Socket->connectToHost(strHost,nPort);
    ui->pushButton->setIcon(QPixmap("send.png"));
    ui->pushButton->setIconSize(QSize(40,40));
     ui->pushButton_2->setIcon(QPixmap("package.png"));
     ui->pushButton_2->setIconSize(ui->pushButton_2->size());
    QMenu * menu = new QMenu("Меню"); // создаём меню Файл
     ui->menuBar->addMenu(menu);
     QAction *actionChangeUser = new QAction("Сменить пользователя",menu);
     connect(actionChangeUser, SIGNAL(triggered()), this, SLOT(slotChangeUser()));
     menu->addAction(actionChangeUser);
     QAction *actionExit = new QAction("Выйти",menu);
     connect(actionExit, SIGNAL(triggered()), this, SLOT(close()));
     menu->addAction(actionExit);
     QAction *actionDeleteAccount = new QAction("Удалить аккаунт",menu);
     connect(actionDeleteAccount, SIGNAL(triggered()), this, SLOT(slotDeleteAccount()));
     menu->addAction(actionDeleteAccount);
    connect(Socket, SIGNAL(connected()), SLOT(slotOpenLogin()));
    connect(Socket, SIGNAL(readyRead()), SLOT(slotReadyRead()));
    connect(this, SIGNAL(MyCallRead()), SLOT(slotReadyRead()));
    connect(this, SIGNAL(goToLogin()), this, SLOT(slotOpenLogin()));
    connect(Socket, SIGNAL(error(QAbstractSocket::SocketError)),this, SLOT(slotError(QAbstractSocket::SocketError)));
    connect(ui->pushButton, SIGNAL(clicked()), SLOT(slotSendToServer()));
    connect(ui->pushButton_2, SIGNAL(clicked()), SLOT(slotSendFile()));
    connect(ui->listWidget, SIGNAL(customContextMenuRequested(QPoint)),   this, SLOT(ShowContextMenu(const QPoint&)));

}

void MyClient::slotReadyRead()
{
    qDebug()<<"readyread";
    QDataStream in(Socket);
    in.setVersion(QDataStream::Qt_5_3);
    for (;;)
    {if(!NextBlockSize)
        { if(Socket->bytesAvailable()<sizeof(qint16)) break;
            in>>NextBlockSize;
        }
          if(Socket->bytesAvailable()>=NextBlockSize) break;
    }
    NextBlockSize=0;
qint8 command;
in>>command;
switch (command) {
case 1:                        //message from client
  {
 QString data, from_name;
 QVector<QPair<int, int> > cypher;
    in>>from_name>>data>>cypher;
    displayMessage(from_name, data, cypher );
    break;}
case 2:               //new client
  {
    QString newname;
    int key_of_cl;
   in>>newname>>key_of_cl;
   open_keys[newname]=key_of_cl;
   if (!list.keys().contains(newname))
   {
   list[newname]=new QListWidgetItem(newname);
   list[newname]->setIcon(QPixmap("doveon.png"));
   ui->listWidget->addItem(list[newname]);
   }
   else list[newname]->setIcon(QPixmap("doveon.png"));
    break;}
case 3:                             //client disconnect
  {
    QString name_exit;
   in>>name_exit;
list[name_exit]->setIcon(QPixmap("doveoff.png"));
   open_keys.remove(name_exit);
    break;}

case 4:                         //все клиенты
  {
    in>>open_keys;
    foreach(QString client, open_keys.keys())
     if (!list.keys().contains(client))
     {
        list[client]=new QListWidgetItem(client);
        list[client]->setIcon(QPixmap("doveon.png"));
        ui->listWidget->addItem(list[client]);
    }
    break;}
case 5:         //ответ на попытку входа
{
    qDebug()<<"case 5";
    QString ans;
    in>>ans;
    if(ans!="No")
    {emit Verification(true);
        in>>openkey;
        qDebug()<<ans;
        name=ans;
        QFile key(name+".bin");
        if(key.open(QIODevice::ReadOnly))
        {
       QDataStream stream(&key);
       stream.setVersion(QDataStream::Qt_5_3);
       stream>>closekey;
       key.close();
        }
    }
    else emit Verification(false);
    break;}
case 6:             //ответ на попытку регистрации
{
    QString ans;
    in>>ans;
    if(ans!="No")
    {emit Checked(true);
        name=ans;
        qDebug()<<closekey;
        QFile key(name+".bin");
        if(key.open(QIODevice::WriteOnly))
        {
       QDataStream stream(&key);
       stream.setVersion(QDataStream::Qt_5_3);
       stream<<closekey;
       key.close();
        }

    }
    else emit Checked(false);
    break;}
case 7:         //пришла история сообщений
{
    QString  from_name;
      QVector <QPair<QString, QVector<QPair<int, int> > > > vect;
       in>>from_name>>vect;
       if (!list.keys().contains(from_name))
      { list[from_name]=new QListWidgetItem(from_name);
           list[from_name]->setIcon(QPixmap("doveoff.png"));
       ui->listWidget->addItem(list[from_name]);}
       dialogs[from_name]=new QTextEdit(this);
               dialogs[from_name]->setReadOnly(true);
       typedef QPair<QString, QVector<QPair<int, int> > > message;
       foreach(const message & pair, vect)
       {
           string messagge_out;
           decrypt(593,closekey, pair.second, messagge_out);
         dialogs[from_name]->append(pair.first+QString::fromStdString(messagge_out));
       }
       break;
}
case 8:      //пришел файл
{
    QString  from_name;
    in>>from_name>>fileName>>fileSize;
    QByteArray arrBlock;
  QDataStream out(&arrBlock, QIODevice::WriteOnly);
  out.setVersion(QDataStream::Qt_5_3);
    if (QMessageBox::Yes == QMessageBox::question(this, "Пришел файл", "Принять файл "+fileName+" от "+from_name+"?", QMessageBox::Yes | QMessageBox::No))
    {
      out<<quint16(0)<<qint8(8)<<qint8(1)<<from_name<<fileName;
      disconnect(Socket, SIGNAL(readyRead()),this, SLOT(slotReadyRead()));
      connect(Socket, SIGNAL(readyRead()),this, SLOT(slotReadFile()));
    }
    else  out<<quint16(0)<<qint8(8)<<qint8(0)<<from_name<<fileName;
    out.device()->seek(0);
    out<<quint16(arrBlock.size()-sizeof(qint16));
    Socket->write(arrBlock);
}
default:
{
    break;
}
}
if(Socket->bytesAvailable()!=0) emit MyCallRead();
}

void MyClient::displayMessage(QString & from, QString & data,QVector<QPair<int, int> >& cypher ) //отображение сообщения
{
    QSound::play("golub.wav");
    string messagge_out;
    decrypt(593,closekey, cypher, messagge_out);
    bool flag=true;
    foreach(QString str,tabs.keys())
           if (str==from) {
               flag=false;
              ui->tabWidget->setCurrentIndex(tabs[str]);
           }
    if(flag==true)
    {
        if(!dialogs.contains(from))
       { dialogs[from]=new QTextEdit(this);
        dialogs[from]->setReadOnly(true);}
ui->tabWidget->addTab( dialogs[from],from);
tabs[from]=ui->tabWidget->count()-1;
ui->tabWidget->setCurrentIndex(tabs[from]);
    }
   dialogs[from]->append(data+QString::fromStdString(messagge_out));
}


void MyClient::slotReadFile()  //чтение файла
{
    qDebug()<<"slotreadfile";
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
     connect(Socket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
     QString savePath = "Downloads/";
     QDir dir;
     dir.mkpath(savePath);
     QFile receiveFile (savePath + fileName);
   if(receiveFile.open(QIODevice::WriteOnly))
     receiveFile.write(fileData);
    receiveFile.close();
    fileData.clear();
   }
}

void MyClient::slotError(QAbstractSocket::SocketError err)   //ошибка подключения
{
   QString strError= "Error: " ;
 if(err==QAbstractSocket::HostNotFoundError)
        strError+=   "The host was not found";
 if(   err==QAbstractSocket::RemoteHostClosedError)
           strError+=           "The remote host is closed";
 if ( err==QAbstractSocket::ConnectionRefusedError)
               strError+=             "The connection was refused";
 QMessageBox msgBox;
         msgBox.setText(strError);
         msgBox.exec();
     this->destroy();
}
void MyClient::slotSendToServer()        //отправление сообщения клиенту
{
    QString addressant=ui->tabWidget->tabText(ui->tabWidget->currentIndex());
    if (addressant.isEmpty())
    {
        QMessageBox msgBox;
                msgBox.setText("Вы не открыли диалог");
                msgBox.exec();
        return;
    }

    if(!open_keys.contains(addressant)) { QMessageBox msgBox;
        msgBox.setText("Вы не можете отправить сообщение , "+addressant+" не онлайн");
        msgBox.exec();
        return;}
   QString msg=ui->textEdit_2->toPlainText();
   if(msg.size()==0) return;
   if(msg.size()>1000)
   {
       QMessageBox msgBox;
               msgBox.setText("Слишком большое сообщение");
               msgBox.exec();
               return;
   }
   QDateTime d=QDateTime::currentDateTime();
   dialogs[addressant]->append(d.toString("dd/MM/yy hh:mm")+": "+name+": "+msg);
   QVector<QPair<int, int> > cypher;
     QVector<QPair<int, int> >   cypher_my;
   crypt(593,123, open_keys[addressant],msg.toStdString(), cypher);
    crypt(593,123, openkey, msg.toStdString(), cypher_my);
    qDebug()<<"my cypher";

    QByteArray arrBlock;
  QDataStream out(&arrBlock, QIODevice::WriteOnly);
  out.setVersion(QDataStream::Qt_5_3);
  out<<quint16(0)<<qint8(2)<<addressant<<d.toString("dd/MM/yy hh:mm")<<name<<cypher<<cypher_my;
  out.device()->seek(0);
  out<<quint16(arrBlock.size()-sizeof(qint16));
  Socket->write(arrBlock);
  qDebug()<<"send message OK";
  ui->textEdit_2->clear();
}

void MyClient::slotSendFile()    //отправить файл
{
   QString addressant=ui->tabWidget->tabText(ui->tabWidget->currentIndex());
   qDebug()<<addressant;
   if (addressant.isEmpty())
   {
       QMessageBox msgBox;
               msgBox.setText("Вы не открыли диалог");
               msgBox.exec();
       return;
   }
   if(!open_keys.contains(addressant)) { QMessageBox msgBox;
       msgBox.setText("Вы не можете отправить файл, "+addressant+" не онлайн");
       msgBox.exec();
       return;}
  QString FilePath = QFileDialog::getOpenFileName(0, "Open Dialog", "", "");
    qDebug()<<FilePath;
   file.setFileName(FilePath);
   QString fileName(FilePath);
   fileName.remove(0, FilePath.lastIndexOf("/")+1);
     qDebug()<<fileName;
  if(file.open(QIODevice::ReadOnly))
   {
       qDebug()<<"file open";
       QByteArray arrBlock, arr;
     QDataStream out(&arrBlock, QIODevice::WriteOnly);
     out.setVersion(QDataStream::Qt_5_3);
     arr=file.readAll();
     int fileSize=file.size();
     qDebug()<<file.size();
     out<<quint16(0)<<qint8(7)<<addressant<<fileName<<fileSize;
     out.device()->seek(0);
     out<<quint16(arrBlock.size()-sizeof(qint16));
     qDebug()<<qint16(arrBlock.size()-sizeof(qint16));
     Socket->write(arrBlock);
     qDebug()<<Socket->waitForBytesWritten();
     Socket->write(arr);

     qDebug()<<"send file OK";

   }
}


void MyClient::slotOpenLogin()   //открыть вход
{
    qDebug()<<"slotOpenLogin";
   Login * login= new Login(this);
      login->show();
      connect(login,SIGNAL(closeLogin()),this, SLOT(slotCloseMain()));
      connect(login, SIGNAL(goToSignUp()), this, SLOT(slotOpenSignUp()));
      connect(login, SIGNAL(tryLogin(QString,QString)), this, SLOT(slotTryLogin(QString,QString)));
      connect(this, SIGNAL(Verification(bool)), login, SLOT(slotVerification(bool)));
     login->exec();
}

void MyClient::slotTryLogin(const QString & login, const QString & password)   //попытка входа
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_3);
    out<<quint16(0)<<qint8(3)<<login<<password;
    out.device()->seek(0);
    out<<quint16(arrBlock.size()-sizeof(qint16));
    Socket->write(arrBlock);
    qDebug()<<"slottryLogin";
}

void MyClient::ShowContextMenu(const QPoint & pos)          //показать контекстное меню ListWidget
{
    QPoint globalPos = ui->listWidget->mapToGlobal(pos);
   if( ui->listWidget->itemAt(pos)==nullptr) return;
    QMenu myMenu;
    myMenu.addAction("Удалить историю");
    QAction* selectedItem = myMenu.exec(globalPos);
    if (selectedItem && selectedItem->text().contains("Удалить историю"))
    {  
          QString name_clean=ui->listWidget->itemAt(pos)->text();
       if (dialogs[name_clean]->toPlainText().size()!=0)
       {
       QByteArray arrBlock;
       QDataStream out(&arrBlock, QIODevice::WriteOnly);
       out.setVersion(QDataStream::Qt_5_3);
       out<<quint16(0)<<qint8(4)<<name<<name_clean;
       out.device()->seek(0);
       out<<quint16(arrBlock.size()-sizeof(qint16));
       Socket->write(arrBlock);
    }
       dialogs[name_clean]->clear();
    }
}

void MyClient::slotOpenSignUp()     //открыть регистрацию
{
    srand(time(NULL));
 closekey = rand() % (593 - 2) + 1;
 openkey = power(123, closekey, 593);
 SignUp *dial=new SignUp(this);
 dial->setModal(true);
     dial->show();
     connect(this, SIGNAL(Checked(bool)), dial,SLOT(slotChecked(bool)));
      connect(dial,SIGNAL(trySignUp(QString, QString)),this, SLOT(slotTrySignUp(QString, QString)));
      connect(dial,SIGNAL(closeSignUp()),this, SLOT(slotCloseMain()));
      connect(dial, SIGNAL(goToLogin()), this, SLOT(slotOpenLogin()));
      dial->exec();
}

void MyClient::slotChangeUser()        //сменить пользователя
{
      qDebug()<<"slotChangeUser";
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_3);
    out<<quint16(0)<<qint8(5)<<name;
    out.device()->seek(0);
    out<<quint16(arrBlock.size()-sizeof(qint16));
    Socket->write(arrBlock);
    ui->tabWidget->clear();
        ui->listWidget->clear();
        tabs.clear();
    list.clear();
    dialogs.clear();
    open_keys.clear();
    emit goToLogin();
    qDebug()<<"slotChangeUser OK";
}

void MyClient::slotDeleteAccount()       //удалить аккаунт
{
    if (QMessageBox::Yes == QMessageBox::question(this, "Close Confirmation", "Are you sure?", QMessageBox::Yes | QMessageBox::No))
    {
        QByteArray arrBlock;
        QDataStream out(&arrBlock, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_3);
        out<<quint16(0)<<qint8(6)<<name;
        out.device()->seek(0);
        out<<quint16(arrBlock.size()-sizeof(qint16));
        Socket->write(arrBlock);
        ui->tabWidget->clear();
            ui->listWidget->clear();
            tabs.clear();
        list.clear();
        dialogs.clear();
        open_keys.clear();
        emit goToLogin();

    }
}
void MyClient::slotCloseMain()
{
    this->destroy();
}
void MyClient::slotTrySignUp(const QString & name,const QString & password )   //регистрация
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_3);
    out<<quint16(0)<<qint8(1)<<name<<password<<openkey;
    out.device()->seek(0);
    out<<quint16(arrBlock.size()-sizeof(qint16));
    Socket->write(arrBlock);
}

MyClient::~MyClient()
{
    delete ui;
}

void MyClient::on_listWidget_itemClicked(QListWidgetItem *item)
{
    bool flag=true;
    foreach(QString str,tabs.keys())
           if (str==item->text()) {
               flag=false;
              ui->tabWidget->setCurrentIndex(tabs[str]);
           }
    if(flag==true)
    {
        if(!dialogs.contains(item->text())){
        dialogs[item->text()]=new QTextEdit(this);
       dialogs[item->text()]->setReadOnly(true); }
ui->tabWidget->addTab( dialogs[item->text()],item->text());
tabs[item->text()]=ui->tabWidget->count()-1;
ui->tabWidget->setCurrentIndex(tabs[item->text()]);
    }
}
void MyClient::closeEvent(QCloseEvent *event)  // show prompt when user wants to close app
{
   event->ignore();
    if (QMessageBox::Yes == QMessageBox::question(this, "Выход", "Выйти?", QMessageBox::Yes | QMessageBox::No))
    {
        event->accept();
    }
}
void MyClient::on_tabWidget_tabCloseRequested(int index)  //close dialog
{

    ui->tabWidget->removeTab(index);
    QList<QString> k=tabs.keys(index);
    QString name=k.takeFirst();
    tabs.remove(name);
    if(!list.contains(name)) dialogs.remove(name);
}

/////////////////////////////////////
int power(int a, int b, int n) {// a^b mod n
    int tmp = a;
    int sum = tmp;
    for (int i = 1; i < b; i++) {
        for (int j = 1; j < a; j++) {
            sum += tmp;
            if (sum >= n) {
                sum -= n;
            }
        }
        tmp = sum;
    }
    return tmp;
}

int mul(int a, int b, int n) {// a*b mod n
    int sum = 0;

    for (int i = 0; i < b; i++) {
        sum += a;

        if (sum >= n) {
            sum -= n;
        }
    }
    return sum;
}

void crypt(int p, int g, int y, string in, QVector <QPair<int, int> > &mas) {  //шифрование

    for (int i = 0; i < in.size(); i++) {
        int m = in[i]+256;
        if (m > 0) {
            srand(time(NULL));
            int k = rand() % (p - 2) + 1; // 1 < k < (p-1)
            int a = power(g, k, p);
            int b = mul(power(y, k, p), m, p);
            mas.push_back( qMakePair(a, b));
        }
    }
}

void decrypt(int p, int x, QVector <QPair<int, int> > mas, string &out) {  //расшифровка

    int i = 0;
    while (i < mas.size()) {
        int a = 0;
        int b = 0;
        a = mas[i].first;
        b = mas[i].second;

        if ((a != 0) && (b != 0)) {
            int deM = mul(b, power(a, p - 1 - x, p), p);// m=b*(a^x)^(-1)mod p =b*a^(p-1-x)mod p
            char m = static_cast<char>(deM);
            out.push_back(m);

            i++;
        }
    }
}



