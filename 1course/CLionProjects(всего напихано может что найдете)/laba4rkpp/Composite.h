#ifndef LABA4RKPP_COMPOSITE_H
#define LABA4RKPP_COMPOSITE_H

#include "Truck.h"
#include "Tipper.h"
#include "TrailerTruck.h"
#include "Van.h"
#include <vector>

class CompositeTrucks : public Truck
{
public:
    double get_loadCapacity() const override;
    int getCntTippers();
    int getCntTrailerTrucks();
    int getCntVans();
    void addTruck(Truck* t);
    ~CompositeTrucks();
    CompositeTrucks* createAlly();
    CompositeTrucks* getComposite() override;
    string getClassType() override;

private:
    vector <Truck*> trucks;
};

#endif //LABA4RKPP_COMPOSITE_H
