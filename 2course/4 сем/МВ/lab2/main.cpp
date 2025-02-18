#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(double x) {
    return sin(0.5 * x) + pow(x, 3);
}

double simpson_integration(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            sum += 2 * f(x);
        } else {
            sum += 4 * f(x);
        }
    }
    return sum * h / 3;
}

int main() {
    double a = 0.0, b = 1.0;
    int n = 100;
    double result = simpson_integration(a, b, n);
    cout << fixed << setprecision(9) << "Приближенное значение интеграла: " << result << endl;
    return 0;
}


