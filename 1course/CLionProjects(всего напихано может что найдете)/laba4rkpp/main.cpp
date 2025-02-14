#include "Truck.h"
#include "Tipper.h"
#include "TrailerTruck.h"
#include "Van.h"
#include "Composite.h"
#include <vector>
#include <functional>
int main()
{
    setlocale(LC_ALL, "Russian");
    CompositeTrucks* trucks = new CompositeTrucks;
    trucks = (*trucks).createAlly();
    if (trucks->getComposite())
        trucks->addTruck(new TrailerTruck("Mers", 251.7, 2.5, 96.8, 2011, 100));

    cout << "Суммарная грузоподъёмность всех грузовиков: " << trucks->get_loadCapacity() << endl << endl;

    int Tippers = (*trucks).getCntTippers();
    int TrailerTrucks = (*trucks).getCntTrailerTrucks();
    int Vans = (*trucks).getCntVans();

    cout << "Грузовики: " << endl << "Самосвалы: " << Tippers << endl
         << "Тягачи: " << TrailerTrucks << endl << "Фургоны: " << Vans << endl;
    delete trucks;
    return 0;
}
