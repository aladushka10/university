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

    int Tippers = (*trucks).getCntTippers();
    int TrailerTrucks = (*trucks).getCntTrailerTrucks();
    int Vans = (*trucks).getCntVans();
    cout << "Грузовики: " << endl << "Самосвалы: " << Tippers << endl
         << "Тягачи: " << TrailerTrucks << endl << "Фургоны: " << Vans << endl;
    return 0;
}
