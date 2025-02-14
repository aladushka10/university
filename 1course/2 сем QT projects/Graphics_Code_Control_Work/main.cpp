#include<QtWidgets/QApplication>
#include "mywidget.h"
#include "mywidget2.h"
#include "mywidget3.h"

int main(int argc, char** argv){
    QApplication app(argc, argv);
    MyWidget w;
    w.show();
    MyWidget2 k;
    k.show();
   // MyWidget3 t;
    //t.show();
    return app.exec();
}
