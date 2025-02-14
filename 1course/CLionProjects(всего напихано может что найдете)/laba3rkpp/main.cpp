#include "Truck.h"
#include "Tipper.h"
#include "TrailerTruck.h"
#include "Van.h"
#include "TrucksFactory.h"
#include <vector>
#include <functional>
int main()
{
    setlocale(LC_ALL, "Russian");
    TrucksFactory* creator = new TipperFactory();
    Truck* t1 = creator->create("Sollers Atlant", 50.0, 3.8, 114.8, 2014, 1.1);
    Truck* t2 = creator->create("Ford transit", 62.0, 4.2, 117.5, 2018, 1.9);
    Truck* t3 = creator->create("Volva", 200.1, 1.9, 75.3, 2014, 22);
    cout << *dynamic_cast<Tipper*>(t1) << endl;
    cout << *dynamic_cast<Tipper*>(t2) << endl;
    cout << *dynamic_cast<Tipper*>(t3) << endl;
    delete creator;

    Truck* v1 = TrucksFactory :: createFactory(Van_ID, "Belaz", 249.3, 2.2, 105.2, 2013, 13);
    cout << *dynamic_cast<Van*>(v1) << endl;

    Truck* tt1 = TrucksFactory :: createFactory(TrailerTruck_ID,"Mers", 251.7, 2.5, 96.8, 2011, 100);
    cout << *dynamic_cast<TrailerTruck*>(tt1) << endl;

    vector <Truck*> Trucks;
    Trucks.push_back(t1);
    Trucks.push_back(t2);
    Trucks.push_back(t3);
    Trucks.push_back(v1);
    Trucks.push_back(tt1);


    int Tippers = 0;
    int TrailerTrucks = 0;
    int Vans = 0;
    for (auto it = Trucks.begin(); it != Trucks.end(); ++it)
    {
        if (typeid(*(*it)).name() == typeid(*t1).name()) { ++Tippers; }
        if (typeid(*(*it)).name() == typeid(*tt1).name()) { ++TrailerTrucks; }
        if (typeid(*(*it)).name() == typeid(*v1).name()) { ++Vans; }
    }
    cout << "Грузовики: " << endl << "Самосвалы: " << Tippers << endl
         << "Тягачи: " << TrailerTrucks << endl << "Фургоны: " << Vans << endl;
    Trucks.clear();
    return 0;
}
