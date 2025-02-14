#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
#include <cstdlib>

int main() {
    setlocale(LC_ALL, "rus");
    double x, eps;

    std::cout << "Введите предел погрешности: ";
    std::cin >> eps;
    if (eps < 0) {
        std::cout << "Я не знаю, что такое отрицательный предел погрешности, так что я возьму это число по модулю))) \n";
    }
    double a = 1, b = 1;
    srand(time(NULL));
    int r = rand();
    x = (double)r / RAND_MAX;
    x *= (a + b);
    x -= a;
    std::cout << "Сегодня ваш Х равен: " << x << "\n" << "\n";

    double result = 1, previous_result = 0;
    double coefficient = 1;
    int n = 1;
    int m = -1;

    while (n == 1 || abs(result - previous_result) > abs(eps)) {
        previous_result = result;
       // std::cout << coefficient << " " << n << "\n";
        coefficient = coefficient * x * (2 * n - 3) / (2 * n)* m;
        result += coefficient;
        ++n;
    }

    std::cout << std::setprecision(16) << "sqrt(1 + x), посчитанный по очень сложной :((( формуле и округленный до предела погрешности: \n" << result << "\n" << "\n";
    std::cout << std::setprecision(16) << " Корень, посчитанный командой sqrt(1 + x): \n" << std::sqrt(1+x) << "\n" << "\n";
    std::cout << "модуль разности: " << abs(std::sqrt(x+1) - result) << "\n";

    return 0;
    
}