#ifndef DIAGRAMITEM_H
#define DIAGRAMITEM_H

#include <QColor>

class diagramItem
{
public:
    diagramItem();
    void setColor(QColor temp);
    QColor getColor() const;
    void setValue(qint32 temp);
    qint32 getValue() const;
    void setName(QString temp);
    QString getName() const;
    void setAngle(double temp);
    double getAngle() const;
    int getSizeH() const;
    int getSizeV() const;
    void setSize(int a , int b);
private:
    QString name;
    QColor color;
    qint32 value;
    double angle;
    qint32  sizeH;
    qint32 sizeV;
};

#endif // DIAGRAMITEM_H
