#ifndef LABA3RKPP_TRUCKSFACTORY_H
#define LABA3RKPP_TRUCKSFACTORY_H
#include "Tipper.h"
#include "TrailerTruck.h"
#include "Van.h"
enum TrucksFactory_ID {Tipper_ID = 0, Van_ID, TrailerTruck_ID};
class TrucksFactory
{
public:
    virtual ~TrucksFactory() {}
    virtual Truck* create(string, double, double, double, int, double) = 0;
    static Truck* createFactory(TrucksFactory_ID ID,string model, double tankVolume, double loadCapacity,
                                double averageSpeed, int year, double k)
    {
        Truck *t;
        switch (ID)
        {
            case Tipper_ID:
            {
                t = new Tipper(model, tankVolume, loadCapacity, averageSpeed, year, k);
            }
                break;
            case Van_ID:
            {
                t = new Van(model, tankVolume, loadCapacity, averageSpeed, year, k);
            }
                break;
            case TrailerTruck_ID:
                t = new TrailerTruck(model, tankVolume, loadCapacity, averageSpeed, year, k);
                break;
            default:
                assert(false);
        }
        return t;
    };
};

class TipperFactory : public TrucksFactory
{
public:
    Truck* create(string model, double tankVolume, double loadCapacity,
                  double averageSpeed, int year, double bodyVolume) override {
        return new Tipper(model, tankVolume, loadCapacity, averageSpeed, year, bodyVolume);
    }
};

class VanFactory : public TrucksFactory
{
    Truck* create(string model, double tankVolume, double loadCapacity,
                  double averageSpeed, int year, double passengerSeats) override {
        return new Van(model, tankVolume, loadCapacity, averageSpeed, year, passengerSeats);
    }
};

class TrailerTruckFactory : public TrucksFactory
{
    Truck* create(string model, double tankVolume, double loadCapacity,
                  double averageSpeed, int year, double trailerCapacity) override {
        return new TrailerTruck(model, tankVolume, loadCapacity, averageSpeed, year, trailerCapacity);
    }
};

#endif
