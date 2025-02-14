#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    string str;
    string arr[1000]; //Максимальное количество строк
    int x, l, N, num;
    N = 0;
    while (getline(fin, str))
    {
        arr[N++] = str;
    }
    fout << "Target information:" << "\n";
    x = l = 0;
    for (int i = l; i < N; i++)
    {
        if ((arr[i].size() == 0) || (arr[i].find_first_not_of(" ") == string::npos))
        {
            x++;
        }
        else
        {
            num = i;
            l = x;
            if (l != 0)
                fout << num - l + 1 << ": " << l << "\n";
            l++;
            x = 0;
        }
    }
    fin.close();
    fout.close();
    system("pause");
    return 0;
}

/*#include <iostream>
#include <math.h>
using namespace std;

double f(double x)
{
    return sin(x*x+2*x);
}

int main() {
    double a, b, eps;//Нижний и верхний пределы интегрирования (a, b), погрешность (eps).
    cin >> a >> b >> eps;
    double I=eps+1, I1=0;//I-предыдущее вычисленное значение интеграла, I1-новое, с большим N.
    for (int N=2; (N<=4)||(fabs(I1-I)>eps); N*=2)
    {
        double h, sum2=0, sum4=0, sum=0;
        h=(b-a)/(2*N);//Шаг интегрирования.
        for (int i=1; i<=2*N-1; i+=2)
        {
            sum4+=f(a+h*i);//Значения с нечётными индексами, которые нужно умножить на 4.
            sum2+=f(a+h*(i+1));//Значения с чётными индексами, которые нужно умножить на 2.
        }
        sum=f(a)+4*sum4+2*sum2-f(b);//Отнимаем значение f(b) так как ранее прибавили его дважды.
        I=I1;
        I1=(h/3)*sum;
    }
    cout << I1 << endl;
    return 0;
}*/
/*#include <iostream>
#include <cmath>
using namespace std;
double m,h;
double f1(double x)
{
    m=pow(x,3) * exp(2*x);
    return m;
}
double f2(double x)
{
    m=1./(1.+sqrt(x));
    return m;
}
double f3(double x)
{
    m=1. / ((x + 1.)*(sqrt(x * x + 1. )));
    return m;
}

double trapezia1(double a,double b,int n,double (*f)(double))
{
    h=(b-a)/n;
    double s=f(a)+f(b);
    for (int i=1; i<n; i++)
    {
        s += 2 * (f(a + i * h));
    }
    s *= h/2;
    return s;
}

double* trapezia(double a,double b, double eps, double (f)(double))
{
    double in = 0, in1 = (f(a) + f(b))/2;
    int col = 0;
    for (int n = 1; fabs(in1 - in) > eps; n*=2)
    {
        double sum = trapezia1(a,b,n,f);
        in=in1;
        in1=sum;
        col=n;
    }
    double* var = new double[2];
    var[0]=in1;
    var[1]=col;

    return var;
}



int main()
{
    double (*f[3])(double) = {f1, f2, f3};
    double* a = new double[3] {0,0,0};
    double* b = new double[3] {0.8, 1.8, 0.3};
    double eps;
    cout << "input the precision: ";
    cin >> eps;
    for (int i = 0; i < 3; i++)
    {
        double* integral = trapezia(a[i],b[i],eps,f[i]);
        cout << i+1 << " integral:" << integral[0] << " " ;
        cout << "accuracy is achieved with the number of partition: " << integral[1] << endl;
        delete [] integral;
    }
    delete [] a;
    delete [] b;
    return 0;
}*/