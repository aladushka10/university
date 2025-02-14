#include "tic_tac_toe.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tic_tac_toe w;
    w.show();
    return a.exec();

}
