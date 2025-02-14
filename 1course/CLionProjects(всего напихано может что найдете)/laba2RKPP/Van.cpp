#include "Van.h"

Van& Van::operator=(const Van& T)
{
    (Truck&)(*this) = (Truck&)T;
    passengerSeats = T.passengerSeats;
    return *this;
}

bool Van::operator==(const Van& T) const
{
    return ((Truck&)(*this) == (Truck&)(T) && passengerSeats == T.passengerSeats);
}

ostream& operator<<(ostream& out, const Van& T)
{
    out << "Фургон ID: " << T.ID << endl;
    out << (Truck&)T;
    out << "Количество пассажирских мест: " << T.passengerSeats << endl;
    return out;
}