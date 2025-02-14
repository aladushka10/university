#include "listwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    listWidget w;
    w.show();
    return a.exec();
}
