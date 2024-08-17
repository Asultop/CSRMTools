#include "smokehelper.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SmokeHelper w;
    w.show();
    return a.exec();
}
