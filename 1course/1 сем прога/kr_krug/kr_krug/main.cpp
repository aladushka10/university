#include <vector>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

class Circle {
private:
    int a1;
    int b1;
    int radius1;
public:
    Circle() : a1(0), b1(0), radius1(0) {};
    Circle (int a, int b, int radius) {
        a1 = a;
        b1 = b;
        radius1 = radius;
    }
    int getRadius() const
    {
        return radius1;
    }
    int getCoordinate1() const
    {
        return a1;
    };
    int getCoordinate2() const
    {
        return b1;
    };
    /*int getSum() const
    {
        return abs(a1 + b1);
    }*/
    void setCoordinate1(int a)
    {
        a1 = a;
    }
    void setCoordinate2(int b)
    {
        b1 = b;
    }
    void setRadius(int radius)
    {
        radius1 = radius;
    }
    double dimension() const
    {
        const double pi = acos(-1.0);
        return pi * pow(radius1, 2);
    }
};
istream& operator >> (istream& in, Circle& c)
{
    int a1, b1, radius1;
    in >> a1 >> b1 >> radius1;
    c.setCoordinate1(a1);
    c.setCoordinate2(b1);
    c.setRadius(radius1);
    return in;
}

ostream& operator << (ostream& out, Circle& c)
{
    out << c.getCoordinate1() << " " <<  c.getCoordinate2() << " " << c.getRadius();
    return out;
}

int main()
{
    ifstream cin("in.txt");
    ofstream cout("out.txt");
    int n;
    cin >> n;
    vector <Circle> round(n);
    for (int i = 0; i < n; i++)
    cin >> round[i];
    double max_max = round[0].dimension();
    double min_min = round[0].dimension();
    for (int i = 0; i < n; ++i) {
        if (round[i].dimension() > max_max) {
            max_max = round[i].dimension();
        }
        if (round[i].dimension() < min_min) {
            min_min = round[i].dimension();
        }
    }

    cout << fixed << setprecision(4) << max_max - min_min;
    return 0;
}

