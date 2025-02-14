#ifndef LABA3RKPP_TRUCKSFACTORY_H
#define LABA3RKPP_TRUCKSFACTORY_H

class Component
{
public:
    virtual Truck* create(string, double, double, double, int, double) = 0;

    virtual int getStrength() = 0;
    virtual void addUnit(Component* p) {assert(false); }
    virtual ~Component() {};
};


#endif
