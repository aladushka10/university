#include "mywidget2.h"

MyWidget2::MyWidget2(QMainWindow* parent) : QMainWindow(parent)
{
    srand(time(0));
    for(int i  = 0; i < 20; ++i){
        data.push_back(rand() % 25 - 12);
    }

    this->setMinimumSize(640, 480);
}

void MyWidget2::paintEvent(QPaintEvent* event = nullptr){
    Q_UNUSED(event);
    QRect rect = this->rect();
    QPainter painter(this);
    painter.setPen(QPen(Qt::red, 3));
    painter.setBrush(QBrush(Qt::darkMagenta));

    int max = *(max_element(data.begin(), data.end()));
    int min = *(min_element(data.begin(), data.end()));
    double dy = rect.height() / data.size();
    double dx = (rect.width() - rect.width() * 0.05) / (max - min);
    dx -= dx* 0.01;
    for(size_t i = 0; i < data.size(); ++i){
        painter.drawRect(std::abs(min) * dx + rect.width() * 0.05, dy * i, data[i] * dx , dy);
//        for(int j = 1; j <= data[i]; j++){
//            painter.drawLine(rect.width() * 0.05 + dx * j, dy * (i), rect.width() * 0.05 + dx * j, dy * (i + 1));
//        }
        painter.drawText(rect.width() * 0.05 * 0.4 + dx * 0.005, dy * i + dy / 2, QString::number(data[i]));
    }
}
