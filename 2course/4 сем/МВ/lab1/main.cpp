#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

// Функция для вычисления Чебышёвских узлов на интервале [a, b] с количеством узлов n
vector<double> chebyshevNodes(double a, double b, int n)
{
    vector<double> nodes;
    for (int i = 0; i <= n; ++i)
    {
        double theta = M_PI * (2 * i + 1) / (2 * (n + 1));
        nodes.push_back((a + b) / 2 + (b - a) / 2 * cos(theta));
    }
    return nodes;
}

// Функция, которую необходимо интерполировать


double f(double x)
{
    return sin(0.5 * x) + pow(x, 3);
}

// Функция для вычисления значения полинома Лагранжа в точке x


double lagrangePolynomial(double x, const vector<double>& nodes, const vector<double>& values)
{
    int n = nodes.size();
    double result = 0.0;
    for (int j = 0; j < n; ++j)
    {
        double term = values[j];
        for (int k = 0; k < n; ++k)
        {
            if (k != j)
            {
                term *= (x - nodes[k]) / (nodes[j] - nodes[k]);
            }
        }
        result += term;
    }
    return result;
}

int main()
{
    double a = 0.0;
    double b = 1.0;

    int n = 4;

    vector<double> nodes = chebyshevNodes(a, b, n);

    // задание значений функции в узлах
    vector<double> values;
    for (double node : nodes) {
        values.push_back(f(node));
    }

    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        cerr << "Unable to open file!" << endl;
        return 1;
    }

    outputFile << "x\t\tP(x)\t\tf(x)\t\tError\n";
    for (double x = a; x <= b; x += 0.1) {
        double p_x = lagrangePolynomial(x, nodes, values);
        double f_x = f(x);
        double error = abs(f_x - p_x); // вычисление погрешности
        outputFile << fixed << setprecision(10) << x << "\t\t" << p_x << "\t\t" << error << "\n";
    }

    outputFile.close();

    return 0;
}




/*#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Функция, которую нужно интерполировать
double original_function(double x) {
    return sin(0.5 * x) + pow(x, 3);
}

// Функция для вычисления Чебышевских узлов
vector<double> generateChebyshevNodes(int n, double a, double b) {
    vector<double> nodes;
    for (int i = 0; i <= n; ++i) {
        double theta = M_PI * (2 * i + 1) / (2 * (n + 1));
        nodes.push_back((a + b) / 2 + (b - a) / 2 * cos(theta));
    }
    return nodes;
}

// Полином Лагранжа
double lagrange_polynomial(vector<double> nodes, double (*f)(double), double x) {
    double result = 0.0;
    for (size_t i = 0; i < nodes.size(); ++i) {
        double term = f(nodes[i]);
        for (size_t j = 0; j < nodes.size(); ++j) {
            if (j != i) {
                term *= (x - nodes[j]) / (nodes[i] - nodes[j]);
            }
        }
        result += term;
    }
    return result;
}

int main() {
    const double a = 0;
    const double b = 1;
    const int num_nodes = 4;
    // Вычисление Чебышевских узлов
    vector<double> nodes = generateChebyshevNodes(num_nodes, a, b);
    // Значения функции в узлах
    vector<double> values(num_nodes);
    for (int i = 0; i < num_nodes; ++i) {
        values[i] = original_function(nodes[i]);
    }

    // Вывод узлов и соответствующих значений функции
    cout << "Chebyshev Nodes:\tFunction Values:" << endl;
    for (int i = 0; i < num_nodes; ++i) {
        cout << nodes[i] << "\t\t\t" << values[i] << endl;
    }
    cout << endl;

    // Построение интерполяционного полинома Лагранжа
    vector<double> interpolated_values(100);
    vector<double> x_values(100);
    for (int i = 1; i <= 100; ++i) {
        double x = i / 100.0;
        x_values[i] = x;
        interpolated_values[i] = lagrange_polynomial(nodes, original_function, x);
    }

    // Вывод значений интерполяционного полинома на экран
    cout << "Interpolated Values:" << endl;
    for (int i = 0; i <= 100; ++i) {
        cout << x_values[i] << "\t\t\t" << interpolated_values[i] << endl;
    }

    return 0;
}
*/