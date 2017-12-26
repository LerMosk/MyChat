
#include "myclient.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyClient w("localhost",2325);
    w.show();

    return a.exec();
}
