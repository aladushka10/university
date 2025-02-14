//#include "mywidget3.h"

//MyWidget3::MyWidget3(QMainWindow* parent) : QMainWindow(parent)
//{
//    data = {
//        {1, 0, -1},
//        {1, 1, 1},
//        {0, 0, 0}
//    };
//    this->setMinimumSize(400, 400);
//}

//void MyWidget3::paintEvent(QPaintEvent* event){
//    Q_UNUSED(event);
//    QPainter painter(this);
//    double up_x = this->width() / 3;
//    double up_y = this->height() / 3;
//    double x_offset = up_x / 2;
//    double y_offset = up_y / 2;
//    painter.setPen(QPen(Qt::blue, 3));
//    painter.drawLine(up_x, 0, up_x, this->height());
//    painter.drawLine(up_x * 2, 0, up_x * 2, this->height());
//    painter.drawLine(0, up_y, this->width(), up_y);
//    painter.drawLine(0, up_y * 2, this->width(), up_y * 2);
//    painter.setPen(QPen(Qt::red, 3));
//    for(size_t i = 0; i < data.size(); ++i)
//    {
//        for(size_t j = 0; j < data[i].size(); j++){
//            double x_center = up_x * j + x_offset;
//            double y_center = up_y * i  + y_offset;
//            if(data[i][j] == 1){
//                QPen(Qt::green, 3);
//                painter.drawLine(x_center + x_offset / 2, y_center + y_offset / 2, x_center - x_offset / 2, y_center - y_offset / 2);
//                painter.drawLine(x_center - x_offset / 2, y_center + y_offset / 2, x_center + x_offset / 2, y_center - y_offset / 2);
//            }
//            if(data[i][j] == 0){
//                QPen(Qt::yellow, 3);
//                painter.drawEllipse(x_center - x_offset / 2, y_center - y_offset / 2, x_offset, y_offset);
//            }
//        }
//    }
//}
