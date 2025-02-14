#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float x;
    cout<<"x = ";
    cin>>x;
    cout << "Введите погрешность: ";
    float eps;
    cin >> eps;
    float f = x;
    float a = x;
    int k = 1;
    while (abs(f) > eps)
    {
        f *= x * x/((k+1)*(k+2));
        k += 2;
        a += f;
    }
    cout.precision(6);
    cout << "sinh(x) по формуле Тейлора: " << a << endl;
    cout << "sinh(x) из библиотеки cmath:  " << sinh(x) << endl;
    return 0; 
}
  
 
