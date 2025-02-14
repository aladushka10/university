#include "flags.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    flags w;
    w.show();
    return a.exec();
}
