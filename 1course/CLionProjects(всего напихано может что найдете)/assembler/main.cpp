#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, ".1251");
    char x1, y1, y11;
    short pr1;
    short x2, y2, pr2;
    int x3, y3, pr3;

    cout << "введите два числа int длиною в 4 байта" << endl;
    cin >> x3 >> y3;
    _asm{
            mov eax, x3
            imul y3
            mov pr3, eax
    }
    cout << pr3 << endl;
    return 0;
            }