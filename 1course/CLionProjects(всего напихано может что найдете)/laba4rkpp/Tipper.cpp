#include "Tipper.h"

Tipper& Tipper::operator=(const Tipper& T)
{
    (Truck&)(*this) = (Truck&)(T);
    bodyVolume = T.bodyVolume;
    return *this;
}

bool Tipper::operator==(const Tipper& T) const
{
    return ((Truck&)(*this) == (Truck&)(T) && bodyVolume == T.bodyVolume);
}

ostream& operator<<(ostream& out, const Tipper& T)
{
    out << "Самосвал ID: " << T.ID << endl;
    out << (Truck&)T;
    out << "Объём кузова: " << T.bodyVolume << endl;
    return out;
}