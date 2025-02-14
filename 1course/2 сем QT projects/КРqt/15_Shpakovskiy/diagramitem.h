#ifndef DIAGRAMITEM_H
#define DIAGRAMITEM_H

#include <QColor>

class diagramItem
{
public:
    diagramItem();
    void setValue(int temp);
    int getValue() const;
    void setAngle(double temp);
    double getAngle() const;
private:
    int value;
    double angle;
};

#endif // DIAGRAMITEM_H
