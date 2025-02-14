#ifndef PICTURE_H
#define PICTURE_H
#include <vector>
#include "diagramitem.h"
#include <QString>
class Picture
{
public:
    Picture();
    std::vector <diagramItem> values;
    QString brushColor;
    QString penColor;
    int penWidth;
};

#endif // PICTURE_H
