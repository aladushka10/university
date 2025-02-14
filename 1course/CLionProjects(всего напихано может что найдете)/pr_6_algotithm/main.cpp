#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;
bool asort1(int a, int b)
{
    return (abs(a) < abs(b));
}

class asort2
{
public:
    bool asort1(int a, int b)
    {
        return (abs(a) < abs(b));
    }
};
void print(int a)
{
    cout << a << " ";
}
class even2
{

public:
    bool operator()
            (int a)
    {
        return (a%2 == 0);
    }
};
bool even1(int a)
{
    return ( a%2 == 0);
}
int main() {
    srand(time(0));
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(rand() % 100);
        if (i % 2 == 0)
            v[i] = -v[i];
    }
    //  sort(v.begin(), v.end(), asort1);
    //  sort(v.begin(), v.end(), asort2());
    sort(v.begin(), v.end(),
            [](int a, int b) {
                return (abs(a) < abs(b));
            }
    );
    for_each(v.begin(), v.end(), print);
    cout << endl;
    int num;
    cout << "enter num";
    cin >> num;
  //  int k = count(v.begin(), v.end(), num);
  // int k = count_if(v.begin(), v.end(), even1);
  // int k = count_if(v.begin(), v.end(), even2());
   int k = count_if(v.begin(), v.end(),
    [](int a)
    {
        return (a % 2 == 0);
    }
   );
    cout << "k = " << k << endl;
    return 0;
}
