#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

double f1(double x)
{
    return exp(sin(x));
}

double f2(double x)
{
    return fabs(2 * sin(2 * x) - 1);
}

vector<double> generateEquidistantNodes(int n, double a, double b)
{
    vector<double> nodes;
    for (int i = 0; i <= n; ++i)
        nodes.push_back(a + i * (b - a) / n);
    return nodes;
}

vector<double> generateChebyshevNodes(int n, double a, double b)
{
    vector<double> nodes;
    for (int i = 0; i <= n; ++i)
    {
        double theta = M_PI * (2 * i + 1) / (2 * (n + 1));
        nodes.push_back((a + b) / 2 + (b - a) / 2 * cos(theta));
    }
    return nodes;
}

vector<double> divided_differences(const vector<double>& x, const vector<double>& y)
{
    int n = x.size();
    vector<double> f(n);
    for (int j = 0; j < n; ++j)
        f[j] = y[j];

    for (int i = 1; i < n; ++i)
        for (int j = n - 1; j >= i; --j)
            f[j] = (f[j] - f[j - 1]) / (x[j] - x[j - i]);
    return f;
}

double interpolate(double x, const vector<double>& nodes, const vector<double>& coeffs)
{
    int n = nodes.size();
    double result = coeffs[0];
    double term = 1.0;
    for (int i = 1; i < n; ++i)
    {
        term *= (x - nodes[i - 1]);
        result += coeffs[i] * term;
    }
    return result;
}

int main()
{
    const double a = -3;
    const double b = 3;
    vector <int> nData = {3, 10, 20};
    /**ofstream ffout("F1.txt");
    ffout << fixed << setprecision(4);
    for (int i = 0; i <= 100; ++i)
    {
        double x = a + i * (b - a) / 100;
        ffout << x << ' ' << f1(x) << '\n';
    }
    ffout.close();
    ffout.open("F2.txt");
    ffout << fixed << setprecision(4);
    for (int i = 0; i <= 100; ++i)
    {
        double x = a + i * (b - a) / 100;
        ffout << x << ' ' << f2(x) << '\n';
    }
    ffout.close();**/
    for (int i = 0; i < 3; ++i)
    {
        int n = nData[i];
        vector<double> equidistantNodes = generateEquidistantNodes(n, a, b);
        vector<double> f1EquidistantValues, f2EquidistantValues;

        for (double node : equidistantNodes)
        {
            f1EquidistantValues.push_back(f1(node));
            f2EquidistantValues.push_back(f2(node));
        }
        ///P1
        vector <double> divDiffP1 = divided_differences(equidistantNodes, f1EquidistantValues);
        ofstream fout("P1_" + to_string(n) + ".txt");
        fout << fixed << setprecision(4);
        for (int i = 0; i <= 100; ++i)
        {
            double x = a + i * (b - a) / 100;
            fout << x << ' ' << interpolate(x, equidistantNodes, divDiffP1) << '\n';
        }
        fout.close();
        ///P2
        vector <double> divDiffP2 = divided_differences(equidistantNodes, f2EquidistantValues);
        fout.open("P2_" + to_string(n) + ".txt");
        fout << fixed << setprecision(4);
        for (int i = 0; i <= 100; ++i)
        {
            double x = a + i * (b - a) / 100;
            fout << x << ' ' << interpolate(x, equidistantNodes, divDiffP2) << '\n';
        }
        fout.close();

        vector<double> chebyshevNodes = generateChebyshevNodes(n, a, b);
        vector<double> f1ChebyshevValues, f2ChebyshevValues;

        for (double node : chebyshevNodes)
        {
            f1ChebyshevValues.push_back(f1(node));
            f2ChebyshevValues.push_back(f2(node));
        }
        ///C1
        vector <double> divDiffC1 = divided_differences(chebyshevNodes, f1ChebyshevValues);
        fout.open("C1_" + to_string(n) + ".txt");
        fout << fixed << setprecision(4);
        for (int i = 0; i <= 100; ++i)
        {
            double x = a + i * (b - a) / 100;
            fout << x << ' ' << interpolate(x, chebyshevNodes, divDiffC1) << '\n';
        }
        fout.close();
        ///C2
        vector <double> divDiffC2 = divided_differences(chebyshevNodes, f2ChebyshevValues);
        fout.open("C2_" + to_string(n) + ".txt");
        fout << fixed << setprecision(4);
        for (int i = 0; i <= 100; ++i)
        {
            double x = a + i * (b - a) / 100;
            fout << x << ' ' << interpolate(x, chebyshevNodes, divDiffC2) << '\n';
        }
        fout.close();
    }
    /*ofstream fout("C2_error.txt");
    fout << fixed << setprecision(6);
    for (int n = 3; n <= 30; ++n)
    {
        vector<double> nodes = generateChebyshevNodes(n, a, b);
        vector<double> f;

        for (double node : nodes)
            f.push_back(f2(node));

        vector <double> divDiff = divided_differences(nodes, f);

        double error = 0.0;
        for (int i = 0; i <= 100; ++i)
        {
            double x = a + i * (b - a) / 100;
            error = max(error, abs(f2(x) - interpolate(x, nodes, divDiff)));
        }
        fout << n << ' ' << error << '\n';
    }*/
    return 0;
}
