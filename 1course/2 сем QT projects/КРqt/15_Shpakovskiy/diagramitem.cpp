#include "diagramitem.h"

diagramItem::diagramItem()
{

}

void diagramItem::setValue(int temp)
{
    value = temp;
}

int diagramItem::getValue() const
{
    return value;
}

void diagramItem::setAngle(double temp)
{
    angle = temp;
}

double diagramItem::getAngle() const
{
    return angle;
}

