#ifndef LABA3RKPP_COMPOSITE_H
#define LABA3RKPP_COMPOSITE_H

#include "Truck.h"
#include "Tipper.h"
#include "TrailerTruck.h"
#include "Van.h"
#include <vector>

class CompositeTrucks : public Truck
{
public:
    int getCntTippers();
    int getCntTrailerTrucks();
    int getCntVans();
    void addTruck(Truck* t);
    ~CompositeTrucks();
    CompositeTrucks* createAlly();
    CompositeTrucks* getComposite();
    string getClassType() override;
private:
    vector <Truck*> trucks;
};
#endif //LABA3RKPP_COMPOSITE_H
