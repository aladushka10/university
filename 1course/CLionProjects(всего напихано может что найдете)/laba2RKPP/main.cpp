#include "Truck.h"
#include "Tipper.h"
#include "TrailerTruck.h"
#include "Van.h"
#include <vector>
#include <iostream>
#include <functional>

int main()
{
    setlocale(LC_ALL, "Russian");
    Van v1("Belaz", 249.3, 2.2, 105.2, 2013, 13), v2, v3(v1), v4;
    v2.set_averageSpeed(113);
    v4.set_tankValue(222.2);
    TrailerTruck tt1("Mers", 251.7, 2.5, 96.8, 2011, 100), tt2;
    tt2.set_trailerCapacity(47);
    Tipper t1("Volva", 200.1, 1.9, 75.3, 2014, 22), t2, t3;
    t2.set_bodyVolume(12);
    cout << v1 << endl << v2 << endl << v3 << endl << v4 << endl;
    if (v1 == v3)
        cout << "equal" << endl;
    else
        cout << "non equal" << endl;
    cout << endl;
    v2 = v1;
    cout << v2 << endl;
    cout << tt1 << endl << tt2 << endl;
    cout << t1.getClassType() << endl << t1 << endl << t2 << endl;
    cout << endl << "Количество объектов-грузовиков: " << Truck::count << endl;

    vector <reference_wrapper<Truck>> Trucks;
    Trucks.push_back(v1);
    Trucks.push_back(v2);
    Trucks.push_back(v3);
    Trucks.push_back(v4);
    Trucks.push_back(tt1);
    Trucks.push_back(tt2);
    Trucks.push_back(t1);
    Trucks.push_back(t2);
    Trucks.push_back(t3);

    int Tippers = 0;
    int TrailerTrucks = 0;
    int Vans = 0;

    for (auto it = Trucks.begin(); it != Trucks.end(); ++it)
    {
        if(typeid((*it).get()).name() == typeid(v1).name())  { ++Vans; }
        if(typeid((*it).get()).name() == typeid(tt1).name())  { ++TrailerTrucks; }
        if(typeid((*it).get()).name() == typeid(t1).name())  { ++Tippers; }
    }
    cout << "Грузовики: " << endl << "Самосвалы: " << Tippers << endl
    << "Тягачи: " << TrailerTrucks << endl << "Фургоны: " << Vans << endl;

    return 0;
}