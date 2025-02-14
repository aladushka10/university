#include "mywidget.h"

MyWidget::MyWidget(QWidget* parent) : QWidget(parent) {
    srand(time(0));
    for(int i = 0; i < 15; ++i){
        data.push_back(rand() % 20);
    }
    this->setMinimumSize(300, 300);
}

void MyWidget::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);
    QRect widgetRect = this->rect();
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 4));
    painter.setBrush(QBrush(Qt::gray));
    int max = *(std::max_element(data.begin(), data.end()));
    double dx = widgetRect.width() / data.size();
    double dy = (widgetRect.height()) / max;
    double height = (widgetRect.height() - 20);
    for(size_t i = 0; i < data.size(); ++i){
        painter.drawRect(dx * i, height, dx, -dy * data[i]);
        painter.drawText(dx * i  + double(dx / 2), height + 10, QString::number(data[i]));
    }
}
