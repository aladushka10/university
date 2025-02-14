#include "diagramitem.h"

diagramItem::diagramItem()
{

}

void diagramItem::setColor(QColor temp)
{
    color = temp;
}

QColor diagramItem::getColor() const
{
    return color;
}

void diagramItem::setValue(qint32 temp)
{
    value = temp;
}

qint32 diagramItem::getValue() const
{
    return value;
}

void diagramItem::setName(QString temp)
{
    name = temp;
}

QString diagramItem::getName() const
{
    return name;
}

void diagramItem::setAngle(double temp)
{
    angle = temp;
}

double diagramItem::getAngle() const
{
    return angle;
}

int diagramItem::getSizeH() const {
    return sizeH;
}

int diagramItem::getSizeV() const {
    return sizeV;
}

void diagramItem::setSize(int a , int b) {
    sizeH = a;
    sizeV = b;
}
