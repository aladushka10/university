#ifndef LABA4RKPP_TRAILERTRUCK_H
#define LABA4RKPP_TRAILERTRUCK_H
#include "Truck.h"
class TrailerTruck : public Truck
{
private:
    double trailerCapacity;
public:
    string getClassType() override { return "Trailer truck"; }
    TrailerTruck() : Truck() { trailerCapacity = 90; }
    TrailerTruck(string model) : Truck(model) { trailerCapacity = 90; }
    TrailerTruck(string model, double tankVolume) : Truck(model, tankVolume) { trailerCapacity = 90; }
    TrailerTruck(string model, double tankVolume, double loadCapacity) :
            Truck(model, tankVolume, loadCapacity) {
        trailerCapacity = 90;
    }
    TrailerTruck(string model, double tankVolume, double loadCapacity, double averageSpeed) :
            Truck(model, tankVolume, loadCapacity, averageSpeed) {
        trailerCapacity = 90;
    }
    TrailerTruck(string model, double tankVolume, double loadCapacity, double averageSpeed, int year) :
            Truck(model, tankVolume, loadCapacity, averageSpeed, year) {
        trailerCapacity = 90;
    }
    TrailerTruck(string model, double tankVolume, double loadCapacity, double averageSpeed,
                 int year, double trailerCapacity) :
            TrailerTruck(model, tankVolume, loadCapacity, averageSpeed, year) {
        this->trailerCapacity = trailerCapacity;
    }
    TrailerTruck(const TrailerTruck& T) : Truck(T), trailerCapacity(T.trailerCapacity) {}

    ~TrailerTruck() { }

    virtual double get_loadCapacity() const override { return loadCapacity; }

    double get_trailerCapacity() const { return trailerCapacity; }

    void set_trailerCapacity(double trailerCapacity) { this->trailerCapacity = trailerCapacity; }

    TrailerTruck& operator =(const TrailerTruck& T);
    bool operator ==(const TrailerTruck& T) const;
    friend ostream& operator <<(ostream& out, const TrailerTruck& T);
};

#endif //LABA4RKPP_TRAILERTRUCK_H
