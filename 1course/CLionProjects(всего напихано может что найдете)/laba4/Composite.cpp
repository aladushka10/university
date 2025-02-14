#include "Composite.h"

int CompositeTrucks::getCntTippers()
{
    int cnt = 0;
    for (int i = 0; i < trucks.size(); i++)
        if (typeid(*trucks[i]) == typeid(Tipper)) { ++cnt; }
    return cnt;
}
int CompositeTrucks::getCntTrailerTrucks()
{
    int cnt = 0;
    for (int i = 0; i < trucks.size(); i++)
        if (typeid(*trucks[i]) == typeid(TrailerTruck)) { ++cnt; }
    return cnt;
}
int CompositeTrucks::getCntVans()
{
    int cnt = 0;
    for (int i = 0; i < trucks.size(); i++)
        if (typeid(*trucks[i]) == typeid(Van)) { ++cnt; }
    return cnt;
}
void CompositeTrucks::addTruck(Truck* t)
{
    trucks.push_back(t);
}

CompositeTrucks::~CompositeTrucks()
{
    for (int i = 0; i < trucks.size(); i++)
        delete trucks[i];
}

CompositeTrucks* CompositeTrucks::createAlly()
{
    CompositeTrucks* ally = new CompositeTrucks;
    ally->addTruck(new Tipper("Sollers Atlant", 50.0, 3.8, 114.8, 2014, 1.1));
    ally->addTruck(new Tipper("Ford transit", 62.0, 4.2, 117.5, 2018, 1.9));
    ally->addTruck(new Tipper("Volva", 200.1, 1.9, 75.3, 2014, 22));
    ally->addTruck(new Van("Belaz", 249.3, 2.2, 105.2, 2013, 13));
    ally->addTruck(new TrailerTruck("Mers", 251.7, 2.5, 96.8, 2011, 100));
    return ally;
}

CompositeTrucks* CompositeTrucks::getComposite()
{
    return this;
}

string CompositeTrucks::getClassType()
{
    return "CompositeTrucks";
}
