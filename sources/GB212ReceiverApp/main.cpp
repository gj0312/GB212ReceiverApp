#include "hj212dialog.h"
#include <QApplication>
#include "gb212.h"
#include <QDebug>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    HJ212Dialog w;
    w.show();

    return a.exec();
}
