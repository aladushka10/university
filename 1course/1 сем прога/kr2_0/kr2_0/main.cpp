#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Distance
{
private:
int first;
int last;
public:
Distance() : first(0), last(0) {};
    
Distance(int a, int b)
{
    first = a;
    last = b;
};
   
int getFirst() const
{
    return first;
};

int getLast() const
{
    return last;
};
    
int getLength() const
{
    return getLast() - getFirst();
};
    void setFirst(int a)
    {
        first = a;
    }
    void setLast(int b)
    {
        last = b;
    }
};
istream& operator >> (istream& in, Distance& d)
{
    int first, last;
    in >> first >> last;
    d.setFirst(first);
    d.setLast(last);
    return in;
}
ostream& operator << (ostream& out, Distance& d)
{
return out << d.getFirst() << " " << d.getLast();
}
bool sravn (Distance& d1, Distance& d2)
{
if (d1.getLength() > d2.getLength())
    return true;
if (d1.getLength() < d2.getLength())
    return false;
return d1.getFirst() < d2.getFirst();
}
    
int main()
{
ifstream cin("in.txt");
ofstream cout("out.txt");
int n;
cin >> n;
vector <Distance> distance(n);
for (int i = 0; i < n; i++)
    cin >> distance[i];
sort(distance.begin(), distance.end(), sravn);
for (int i = 0; i < n; i++)
cout << distance[i] << endl;
return 0;
}
