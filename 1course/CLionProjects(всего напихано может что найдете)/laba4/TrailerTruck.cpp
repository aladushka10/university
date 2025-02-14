#include "TrailerTruck.h"

TrailerTruck& TrailerTruck::operator=(const TrailerTruck& T)
{
    (Truck&)(*this) = (Truck&)T;
    trailerCapacity = T.trailerCapacity;
    return *this;
}

bool TrailerTruck::operator==(const TrailerTruck& T) const
{
    return ((Truck&)(*this) == (Truck&)(T) && trailerCapacity == T.trailerCapacity);
}

ostream& operator<<(ostream& out, const TrailerTruck& T)
{
    out << "Тягач ID: " << T.ID << endl;
    out << (Truck&)T;
    out << "Объём прицепа: " << T.trailerCapacity << endl;
    return out;
}