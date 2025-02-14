#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> powersOfTwo(long long a)
{
    vector<int> powers;
    int k = 0;
    while(a != 0)
    {
        if(a % 2)
            powers.push_back(k);
        a /= 2;
        k++;
    }
    return powers;
}

int main() {
    //ifstream fin("input.txt");
    //ofstream fout("output.txt");
    long long n;
    vector <int> arr;
    cin >> n;
    arr = powersOfTwo(n);
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << endl;
    return 0;
}
