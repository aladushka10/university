#include <iostream>
#include "Money.h"

using namespace std;

int main()
{
    try
    {
        double pd, sh, p;
        cout << "паунды 1 человека: " << endl;
        cin >> pd;
        cout << "шилинги 1 человека: " << endl;
        cin >> sh;
        cout << "пенсы 1 человека: " << endl;
        cin >> p;
        bool isHalf;
        if (int(pd) != pd || int(sh) != sh || (p != int(p) && p - int(p) != 0.5))
        {
            throw 1;
        }
        else
        {
            if (p == int(p))
                isHalf = false;
            else
                isHalf = true;
        }
        Money m1(int(pd), int(sh), int(p), isHalf);
        cout << "паунды 2 человека: " << endl;
        cin >> pd;
        cout << "шилинги 2 человека: " << endl;
        cin >> sh;
        cout << "пенсы 2 человека: " << endl;
        cin >> p;
        if (int(pd) != pd || int(sh) != sh || (p != int(p) && p - int(p) != 0.5))
        {
            throw 1;
        }
        else
        {
            if (p == int(p))
                isHalf = false;
            else
                isHalf = true;
        }
        Money m2(int(pd), int(sh), int(p), isHalf);
        Money sum = m1 + m2;
        cout << "сумма 1 и 2: " << sum << endl;
        Money raz = m1 - m2;
        cout << "разность 1 и 2: " << raz << endl;
        if (m1 > m2)
            cout << "у 1 денег больше";
        if (m1 < m2)
            cout << "у 2 денег больше";
        if (m1 == m2)
            cout << "денег поровну";
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
            case 3:
                cout << "кол-во паундов вышло за пределы лимита";
                break;
            case 4:
                cout << "некорректные значения в set";
                break;
            default:
                cout << "неопознанная ошибка";
                break;
        }
    }
    return 0;
}
