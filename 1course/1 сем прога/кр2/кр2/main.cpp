#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
double f(double x)
{
    return(sqrt(x) + x * x + log(x));
}
int main() {
    freopen("equation2.in", "r", stdin);
    freopen("equation2.out", "w", stdout);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        double a, b, c;
        scanf("%lf %lf %lf", &a, &b, &c);
        double eps = 0.00000000001;
        while (b - a >= eps)
        {
            double mid = (a + b) / 2;
            double current = f(mid);
            if(current < c)
                a = mid + eps;
            else
                b = mid - eps;
        }
        double mid = (a + b) / 2;
        double current = f(mid);
        if(abs(current - c) <= 0.001)
            printf("%lf\n", mid);
        else
            printf("No solution\n");
    }
    return 0;
}
