#include "money.h"
#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    try
    {
        double pnd, sh, pen;
        cout << "паунды 1 человека: " << endl;
        cin >> pnd;
        cout << "шилинги 1 человека: " << endl;
        cin >> sh;
        cout << "пенсы 1 человека: " << endl;
        cin >> pen;

        if (int(pnd) != pnd || int(sh) != sh || (pen != int(pen) && pen - int(pen) != 0.5))
            throw 1;

        Money money1(int(pnd), int(sh), pen);
        cout << "паунды 2 человека: " << endl;
        cin >> pnd;
        cout << "шилинги 2 человека: " << endl;
        cin >> sh;
        cout << "пенсы 2 человека: " << endl;
        cin >> pen;
        if (int(pnd) != pnd || int(sh) != sh || (pen != int(pen) && pen - int(pen) != 0.5))
            throw 1;
        Money money2(int(pnd), int(sh), pen);
        Money sum = money1 + money2;
        cout << "сумма 1 и 2: ";
        sum.out();
        cout << endl;
        Money raz = money1 - money2;
        cout << "разность 1 и 2: ";
        raz.out();
        cout << endl;
        if (money1 > money2)
            cout << "у 1 денег больше" << endl;
        if (money1 < money2)
            cout << "у 2 денег больше" << endl;;
        if(money1 == money2)
            cout << "денег поровну" <<  endl;;
    }
    catch(int err)
    {
        switch(err)
        {
            case 1:
                cout << "ошибка при вводе. некорректные данные";
                break;
            case 2:
                cout << "в конструкторе некорректные данные";
                break;
            default:
                cout << "неопознанная ошибка";
                break;
        }
    }
    return 0;
}
