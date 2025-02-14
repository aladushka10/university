#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

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
    
    cout << "Interpolation results:\n";
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

        vector <double> divDiffP1 = divided_differences(equidistantNodes, f1EquidistantValues);
        cout << "Interpolation for f1 with equidistant nodes (n = " << n << "):\n";
        cout << "x\t\tInterpolated f1(x)\n";
        for (int i = 0; i <= 100; ++i)
        {
            double x = a + i * (b - a) / 100;
            cout << fixed << setprecision(4) << x << '\t' << interpolate(x, equidistantNodes, divDiffP1) << '\n';
        }
        
        vector <double> divDiffP2 = divided_differences(equidistantNodes, f2EquidistantValues);
        cout << "Interpolation for f2 with equidistant nodes (n = " << n << "):\n";
        cout << "x\t\tInterpolated f2(x)\n";
        for (int i = 0; i <= 100; ++i)
        {
            double x = a + i * (b - a) / 100;
            cout << fixed << setprecision(4) << x << '\t' << interpolate(x, equidistantNodes, divDiffP2) << '\n';
        }

        vector<double> chebyshevNodes = generateChebyshevNodes(n, a, b);
        vector<double> f1ChebyshevValues, f2ChebyshevValues;

        for (double node : chebyshevNodes)
        {
            f1ChebyshevValues.push_back(f1(node));
            f2ChebyshevValues.push_back(f2(node));
        }

        vector <double> divDiffC1 = divided_differences(chebyshevNodes, f1ChebyshevValues);
        cout << "Interpolation for f1 with Chebyshev nodes (n = " << n << "):\n";
        cout << "x\t\tInterpolated f1(x)\n";
        for (int i = 0; i <= 100; ++i)
        {
            double x = a + i * (b - a) / 100;
            cout << fixed << setprecision(4) << x << '\t' << interpolate(x, chebyshevNodes, divDiffC1) << '\n';
        }
        
        vector <double> divDiffC2 = divided_differences(chebyshevNodes, f2ChebyshevValues);
        cout << "Interpolation for f2 with Chebyshev nodes (n = " << n << "):\n";
        cout << "x\t\tInterpolated f2(x)\n";
        for (int i = 0; i <= 100; ++i)
        {
            double x = a + i * (b - a) / 100;
            cout << fixed << setprecision(4) << x << '\t' << interpolate(x, chebyshevNodes, divDiffC2) << '\n';
        }
    }
    return 0;
}
