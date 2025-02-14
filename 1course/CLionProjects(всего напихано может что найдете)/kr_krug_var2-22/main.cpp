#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

class Circle {
private:
    int x1;
    int y1;
    int r1;
public:
    Circle() : x1(0), y1(0), r1(0) {};
    Circle (int x, int y, int radius) {
        x1 = x;
        y1 = y;
        r1 = radius;
    }
    int getRadius() const
    {
        return r1;
    }
    int getCoordinate1() const
    {
        return x1;
    };
    int getCoordinate2() const
    {
        return y1;
    };
    void setCoordinate1(int x)
    {
        x1 = x;
    }
    void setCoordinate2(int y)
    {
        y1 = y;
    }
    void setRadius(int radius)
    {
        r1 = radius;
    }
    bool thirdQuarter()
    {
        if (x1 + r1 < 0 && y1 + r1 < 0)
            return true;
        else
            return false;
    }
};
istream& operator >> (istream& in, Circle& c)
{
    int x1, y1, r1;
    in >> x1 >> y1 >> r1;
    c.setCoordinate1(x1);
    c.setCoordinate2(y1);
    c.setRadius(r1);
    return in;
}
int main()
{
    ifstream cin("in.txt");
    ofstream cout("out.txt");
    int n, count = 0;
    cin >> n;
    vector <Circle> round(n);
    for (int i = 0; i < n; i++)
        cin >> round[i];
    for (int i = 0; i < n; i++)
        if(round[i].thirdQuarter())
            count++;
    cout << count ;
    return 0;
}
