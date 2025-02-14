#ifndef TIPPER_H
#define TIPPER_H

#include "Truck.h"

class Tipper : public Truck
{
private:
    double bodyVolume;
public:
    string getClassType() override { return "Tipper"; }
    Tipper() : Truck() { bodyVolume = 18; }
    Tipper(string model) : Truck(model) { bodyVolume = 18; }
    Tipper(string model, double tankVolume) : Truck(model, tankVolume) { bodyVolume = 18; }
    Tipper(string model, double tankVolume, double loadCapacity) : Truck(model, tankVolume, loadCapacity) { bodyVolume = 18; }
    Tipper(string model, double tankVolume, double loadCapacity, double averageSpeed) :
            Truck(model, tankVolume, loadCapacity, averageSpeed) { bodyVolume = 18; }
    Tipper(string model, double tankVolume, double loadCapacity, double averageSpeed, int year) :
            Truck(model, tankVolume, loadCapacity, averageSpeed, year) {
        bodyVolume = 18;
    }
    Tipper(string model, double tankVolume, double loadCapacity, double averageSpeed, int year,
           double bodyVolume) :
            Tipper(model, tankVolume, loadCapacity, averageSpeed, year) {
        this->bodyVolume = bodyVolume;
    }
    Tipper(const Tipper& T) : Truck(T), bodyVolume(T.bodyVolume) {}

    ~Tipper() { }

    double get_bodyVolume() const { return bodyVolume; }

    void set_bodyVolume(double bodyVolume) { this->bodyVolume = bodyVolume; }

    Tipper& operator =(const Tipper& T);
    bool operator ==(const Tipper& T) const;
    friend ostream& operator <<(ostream& out, const Tipper& T);

};

#endif

