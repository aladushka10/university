#include <iostream>
using namespace std;
int main()
{
    int n;
cin>>n;
int a = 2;
while(a*a <= n) {
if(n % a == 0) {
cout << a << " ";
n/=a;
}
else{
a++;
}
}
if(n > 1)
    cout << n <<endl;

    return 0;
}
