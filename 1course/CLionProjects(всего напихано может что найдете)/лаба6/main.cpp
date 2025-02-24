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

double calculate(double a, double b, double eps, double(*func)(double))
{
    int n = 100;
    double answer1 = 0.0;
    double answer2 = 0.0;
    do
    {
        answer1 = func(a) + func(b);
        double h = (b - a) / n;
        for (double j = a + h; j < b; j += 2 * h)
            answer1 += 4 * func(j);
        for (double j = a + 2 * h; j < b; j += 2 * h)
            answer1 += 2 * func(j);
        answer1 *= h / 3.;
        n += 100;

        answer2 = func(a) + func(b);
        h = (b - a) / n;
        for (double j = a + h; j < b; j += 2 * h)
            answer2 += 4 * func(j);
        for (double j = a + 2 * h; j < b; j += 2 * h)
            answer2 += 2 * func(j);
        answer2 *= h / 3.;

        n += 100;
    }
    while (eps < abs(answer1 - answer2));
    return answer2;
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
    double* var = new double[2];
    var[0] = integr1;
    var[1] = amount;

    return var;
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
        cout << i + 1 << " интеграл: " << calculate(arrA[i], arrB[i], eps, func[i]) << endl;
        cout << "количество разбиений, на котором достигается заданная точность: " << calculate(arrA[i + 1], arrB[i + 1], eps, func[i + 1]) << endl;
    }
    delete[] arrA;
    delete[] arrB;
    return 0;
}
