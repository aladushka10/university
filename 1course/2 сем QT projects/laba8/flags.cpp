#include "flags.h"
#include "ui_flags.h"
#include <QPainter>
#include <QTabWidget>

flags::flags(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::flags)
{
    ui->setupUi(this);
}

flags::~flags()
{
    delete ui;
}

void flags::paintEvent (QPaintEvent*) {
    QPainter painter(this);
    QBrush clear(qRgb(214, 214, 214));
    painter.fillRect(0, 0, this->width(), this->height(), clear);
    if(ui->tabWidget->currentIndex() == 0)
    {
        //касается боков
        if (2 * this->width() / 3 <= this->height())
        {
            qreal c = this->width();
            QBrush brush(qRgb(200, 16, 46));//красный
            painter.fillRect(0, (this->height() - 2 * c / 3) / 2, c, 2 * c / 3, brush);
            QBrush brush2(qRgb(255, 255, 255));//белый
            painter.fillRect(0, (this->height() - 2 * c / 3) / 2 + 2 * c / 9, c, 2 * c / 9, brush2);
        }
        //касается сверху снизу
        else
        {
            qreal c = 3 * this->height() / 2;
            QBrush brush(qRgb(200, 16, 46));
            painter.fillRect((this->width() - c) / 2, 0, c, 2 * c / 3, brush);
            QBrush brush2(qRgb(255, 255, 255));
            painter.fillRect((this->width() - c) / 2, 2 * c / 9, c, 2 * c / 9, brush2);
        }
    }

    else
    {
        //касается боков
        if (this->width() / 2 <= this->height())
        {
            qreal x = this->width() / 2;
            //прямоугольник
            QBrush brush(qRgb(200, 0, 0));
            painter.fillRect(0, (this->height() - x) / 2, 2 * x, x, brush);
            brush.setColor(qRgb(255, 230, 0));// желтый
            QPolygon triangle;
            //верхний левый
            triangle << QPoint(0, (this->height() - x) / 2)
                     << QPoint(3 * x / 10, (this->height() - x) / 2)
                     << QPoint(x, this->height() / 2);
            painter.setBrush(brush);
            painter.setPen(Qt::NoPen);
            painter.drawPolygon(triangle);
            triangle.clear();
            //верхний центральный
            triangle << QPoint(x, this->height() / 2)
                     << QPoint(9 * x / 10, (this->height() - x) / 2)
                     << QPoint(11 * x / 10, (this->height() - x) / 2);
            painter.drawPolygon(triangle);
            triangle.clear();
            //верхний правый
            triangle << QPoint(x, this->height() / 2)
                     << QPoint(17 * x / 10, (this->height() - x) / 2)
                     << QPoint(2 * x, (this->height() - x) / 2);
            painter.drawPolygon(triangle);
            triangle.clear();
            //нижний левый
            triangle << QPoint(0, (this->height() - x) / 2 + x)
                     << QPoint(3 * x / 10, (this->height() - x) / 2 + x)
                     << QPoint(x, this->height() / 2);
            painter.drawPolygon(triangle);
            triangle.clear();
            //нижний центральный
            triangle << QPoint(x, this->height() / 2)
                     << QPoint(9 * x / 10, (this->height() - x) / 2 + x)
                     << QPoint(11 * x / 10, (this->height() - x) / 2 + x);
            painter.drawPolygon(triangle);
            triangle.clear();
            //нижний правый
            triangle << QPoint(x, this->height() / 2)
                     << QPoint(17 * x / 10, (this->height() - x) / 2 + x)
                     << QPoint(2 * x, (this->height() - x) / 2 + x);
            painter.drawPolygon(triangle);
            triangle.clear();
            //левый центральный
            triangle << QPoint(x, this->height() / 2)
                     << QPoint(0, (this->height() - x) / 2 + 2 * x / 5)
                     << QPoint(0, (this->height() - x) / 2 + 3 * x / 5);
            painter.drawPolygon(triangle);
            triangle.clear();
            //правый центральный
            triangle << QPoint(x, this->height() / 2)
                     << QPoint(2 * x, (this->height() - x) / 2 + 2 * x / 5)
                     << QPoint(2 * x, (this->height() - x) / 2 + 3 * x / 5);
            painter.drawPolygon(triangle);
            //красный круг
            brush.setColor(qRgb(200, 0, 0));
            painter.setBrush(brush);
            painter.drawEllipse(QPoint(x, this->height() / 2), 5 * this->width() / 56, 5 * this->width() / 56);
            //желтый круг
            brush.setColor(qRgb(255, 230, 0));
            painter.setBrush(brush);
            painter.drawEllipse(QPoint(x, this->height() / 2), this->width() / 14, this->width() / 14);
        }
        //касается сверху снизу
        else
        {
            qreal x = this->height();
            QBrush brush(qRgb(200, 0, 0));
            painter.fillRect((this->width() - 2 * x) / 2, 0, 2 * x, x, brush);
            brush.setColor(qRgb(255, 230, 0));
            painter.setBrush(brush);
            painter.setPen(Qt::NoPen);
            QPolygon triangle;
            //верхний левый
            triangle << QPoint(this->width() / 2, x / 2)
                     << QPoint((this->width() - 2 * x) / 2 + 3 * x / 10, 0)
                     << QPoint((this->width() - 2 * x) / 2, 0);
            painter.drawPolygon(triangle);
            triangle.clear();
            //верхний центральный
            triangle << QPoint(this->width() / 2, x / 2)
                     << QPoint((this->width() - 2 * x) / 2 + 9 * x / 10, 0)
                     << QPoint((this->width() - 2 * x) / 2 + 11 * x / 10, 0);
            painter.drawPolygon(triangle);
            triangle.clear();
            //верхний правый
            triangle << QPoint(this->width() / 2, x / 2)
                     << QPoint((this->width() - 2 * x) / 2 + 17 * x / 10, 0)
                     << QPoint((this->width() - 2 * x) / 2 + 2 * x, 0);
            painter.drawPolygon(triangle);
            triangle.clear();
            //нижний левый
            triangle << QPoint(this->width() / 2, x / 2)
                     << QPoint((this->width() - 2 * x) / 2 + 3 * x / 10, x)
                     << QPoint((this->width() - 2 * x) / 2, x);
            painter.drawPolygon(triangle);
            triangle.clear();
            //нижний центральный
            triangle << QPoint(this->width() / 2, x / 2)
                     << QPoint((this->width() - 2 * x) / 2 + 9 * x / 10, x)
                     << QPoint((this->width() - 2 * x) / 2 + 11 * x / 10, x);
            painter.drawPolygon(triangle);
            triangle.clear();
            //нижний правый
            triangle << QPoint(this->width() / 2, x / 2)
                     << QPoint((this->width() - 2 * x) / 2 + 17 * x / 10, x)
                     << QPoint((this->width() - 2 * x) / 2 + 2 * x, x);
            painter.drawPolygon(triangle);
            triangle.clear();
            //центральный левый
            triangle << QPoint(this->width() / 2, x / 2)
                     << QPoint((this->width() - 2 * x) / 2, 2 * x / 5)
                     << QPoint((this->width() - 2 * x) / 2, 3 * x / 5);
            painter.drawPolygon(triangle);
            triangle.clear();
            //центральный правый
            triangle << QPoint(this->width() / 2, x / 2)
                     << QPoint((this->width() - 2 * x) / 2 + 2 * x, 2 * x / 5)
                     << QPoint((this->width() - 2 * x) / 2 + 2 * x, 3 * x / 5);
            painter.drawPolygon(triangle);
            triangle.clear();
            //красный круг
            brush.setColor(qRgb(200, 0, 0));
            painter.setBrush(brush);
            painter.drawEllipse(QPoint(this->width() / 2, x / 2), 5 * this->height() / 28, 5 * this->height() / 28);
            //желтый круг
            brush.setColor(qRgb(255, 230, 0));
            painter.setBrush(brush);
            painter.drawEllipse(QPoint(this->width() / 2, x / 2), this->height() / 7, this->height() / 7);
        }
    }
}

void flags::on_tabWidget_currentChanged(int)
{
    QWidget::update();
}

