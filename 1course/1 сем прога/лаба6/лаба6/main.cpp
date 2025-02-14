#include <iostream>
#include <cmath>
using namespace std;
 double integral1(double x)
 {
     return (sqrt(exp(x) - 1.));
 }

 double integral2(double x)
 {
     return (exp(x) * sin(x));
 }

 double integral3(double x)
 {
     return ((x * x - 1.) * pow(10., - 2. * x));
 }

double calculate(double a, double b, int n, double(*func)(double))
{
    double h = (b - a)/ n;
    double answer = 0.0;
    for (int i = 1; i < n ; i += 2)
        answer += h / 3 * (func(a + (i - 1) * h) + 4 * func(a + i * h) + func(a + (i + 1) * h));
    return answer;
}
double* simpson(double a, double b, double eps, double(*func)(double))
{
    double integr = 0, integr1 = (func(a) + func(b)) / 2;
    int amount = 0;
    for (int n = 1; fabs(integr1 - integr) > eps; n *= 2)
    {
        double sum = calculate(a, b, n, func);
        integr = integr1;
        integr1 = sum;
        amount = n;
    }
    double* array = new double[2];
    array[0] = integr1;
    array[1] = amount;

    return array;
}

int main() {
    setlocale(LC_ALL, "rus");
    double eps;
    cout << "введите точность: ";
    cin >> eps;
    while(eps > 0.1 || eps < 0.0000001){
        cout << "точность выходит за рамки условия, введите снова: ";
        cin >> eps;
    }
    double (*func[3])(double) = {integral1, integral2, integral3};
    double* arrA = new double[3]{0.2, 0.0, 0.0};
    double* arrB = new double[3]{2.1, M_PI / 2., 0.5};
    for (int i = 0; i < 3; i++){
       double* integral = simpson(arrA[i], arrB[i], eps, func[i]);
            cout << i + 1 << " интеграл: " << integral[0] << endl;
   cout << "количество разбиений, на котором достигается заданная точность: " << integral[1] << endl;
        delete[] integral;
    }
    delete[] arrA;
    delete[] arrB;
        return 0;
    }


