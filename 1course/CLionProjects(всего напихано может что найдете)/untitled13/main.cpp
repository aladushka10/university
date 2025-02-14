#include <iostream>
#include <utility>

using namespace std;

int main()
{
    pair <int, double> p1(12,12.5), p2(p1),p3;
    cout<<p1.first << " "<<p1.second<< endl;
    cout<<p2.first << " "<<p2.second<< endl;
    cout<<p3.first << " "<<p3.second<< endl;
    p3 = make_pair(31, 21.12);
    cout<<p3.first << " "<<p3.second<< endl;
    p3.first +=2;
    cout<<p3.first << " "<<p3.second<< endl;

    if (p1==p2)
        cout<<"equal\n";
    else cout <<"not equal\n";
    system("pause");
    return 0;
}
