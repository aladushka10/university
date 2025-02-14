#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;
void print(int a)
{
    cout << a << " ";
}
int main() {
    int m = 0, n = 0;
    [&, n] (int a) mutable {m = ++n + a; } (4);
    cout << "m = " << m << "; n = " << n << endl;
    srand(time(0));
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(rand() % 100);
        if (i % 2 == 0)
            v[i] = -v[i];
    }
    for_each(v.begin(), v.end(), print);
    int evenCount = 0;
    for_each(v.begin(), v.end(),
             [&evenCount] (int n)
             {
        if (n % 2 == 0) ++evenCount;
             }
             );
    cout << endl << "there are " << evenCount << " numbers in vector\n";
    return 0;
}
