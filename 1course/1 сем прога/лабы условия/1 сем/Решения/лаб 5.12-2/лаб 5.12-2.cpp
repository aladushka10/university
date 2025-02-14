#include <iostream>
#include<cmath>
double f1(double x) {
    double st = pow(x, 0.23);
    return st * sin(0.4 * x);
}
double f2(double x) {
    return sin(0.4 * x) * sin(0.4 * x) / (x * x + 3.5);
}
double f3(double x) {
    return 1.1 * exp(x / (1 + x * x)) / (x * x + 1.1);
}
double integral(double a, double b, double eps, double (*f)(double)) {
    long long n = 2;
    double pr_integ = 0, integ = 0, h, x1, x2;
    do {
        pr_integ = integ;
        h = (b - a) / n;
        integ = 0;
        for (long long i = 0; i < n; ++i) {
            x1 = a + i * h;
            x2 = a + (i + 1) * h;
            integ += (x2 - x1) * (f(x1) + f(x2)) / 2;
        }
        n *= 2;
        // n += 2;
    } while (std::abs(integ - pr_integ) > std::abs(eps));
    std::cout << " интеграл равен " << integ << " при n = " << n << "\n";
    return 1;
}
int main() {
    setlocale(LC_ALL, "rus");
    double a = 0, b = 1, eps;
    std::cout << "Введите предел погрешности: ";
    std::cin >> eps;
    if (eps < 0) {
        std::cout << "Я не знаю, что такое отрицательный предел погрешности, так что я возьму это число по модулю))) \n";
    }
    if (eps > 1) {
        std::cout << "предел слишком большой :(";
        return 1;
    }
    std::cout << "Первый";
    integral(a, b, eps, f1);
    std::cout << "Второй";
    integral(a, b, eps, f2);
    std::cout << "Третий";
    integral(a, b, eps, f3);
    return 0;
}