#ifndef VAN_H
#define VAN_H

#include "Truck.h"

class Van : public Truck
{
private:
    int passengerSeats;
public:
    string getClassType() override { return "Van"; }
    Van() : Truck() { passengerSeats = 12; }
    Van(string model) : Truck(model) { passengerSeats = 12; }
    Van(string model, double tankVolume) : Truck(model, tankVolume) { passengerSeats = 12; }
    Van(string model, double tankVolume, double loadCapacity) : Truck(model, tankVolume, loadCapacity) {
        passengerSeats = 12;
    }
    Van(string model, double tankVolume, double loadCapacity, double averageSpeed) :
            Truck(model, tankVolume, loadCapacity, averageSpeed) {
        passengerSeats = 12;
    }
    Van(string model, double tankVolume, double loadCapacity, double averageSpeed, int year) :
            Truck(model, tankVolume, loadCapacity, averageSpeed, year) {
        passengerSeats = 12;
    }
    Van(string model, double tankVolume, double loadCapacity, double averageSpeed, int year,
        int passengerSeats) :
            Van(model, tankVolume, loadCapacity, averageSpeed, year) {
        this->passengerSeats = passengerSeats;
    }
    Van(const Van& T) : Truck(T), passengerSeats(T.passengerSeats) {}

    ~Van() {}

    int get_passengerSeats() const { return passengerSeats; }

    void set_passengerSeats(int passengerSeats) { this->passengerSeats = passengerSeats; }

    Van& operator =(const Van& T);
    bool operator ==(const Van& T) const;
    friend ostream& operator <<(ostream& out, const Van& T);
};

#endif