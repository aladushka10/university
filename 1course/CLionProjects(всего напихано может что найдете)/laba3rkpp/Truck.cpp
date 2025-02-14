#include "Truck.h"

int Truck::NextID = 1;
int Truck::count = 0;

Truck::Truck(const Truck& T) : ID(NextID++)
{
    model = T.model;
    tankVolume = T.tankVolume;
    loadCapacity = T.loadCapacity;
    averageSpeed = T.averageSpeed;
    year = T.year;
    ++count;
}

Truck& Truck::operator=(const Truck& T)
{
    if (&T == this)
        return *this;
    model = T.model;
    tankVolume = T.tankVolume;
    loadCapacity = T.loadCapacity;
    averageSpeed = T.averageSpeed;
    year = T.year;
    return *this;
}

bool Truck::operator==(const Truck& T) const
{
    return (model == T.model && tankVolume == T.tankVolume && loadCapacity == T.loadCapacity
            && averageSpeed == T.averageSpeed && year == T.year);
}

ostream& operator<<(ostream& out, const Truck& T)
{
    out << "Модель: " << T.model << endl;
    out << "Объём бака: " << T.tankVolume << endl;
    out << "Грузоподъёмность: " << T.loadCapacity << endl;
    out << "Средняя скорость: " << T.averageSpeed << endl;
    out << "Год издания: " << T.year << endl;
    return out;
}