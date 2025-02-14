#ifndef MYWIDGET2_H
#define MYWIDGET2_H
#include <QtWidgets/QMainWindow>
#include <qpainter.h>
class MyWidget2 : public QMainWindow
{
    Q_OBJECT
public:
    MyWidget2(QMainWindow* parent = nullptr);
    void paintEvent(QPaintEvent* event);
private:
    std::vector<short> data;
};

#endif // MYWIDGET2_H
