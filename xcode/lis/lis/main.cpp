#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int UpperBound(const vector<int> &arr, int k)
{
    int middle = 0;
    int l = 0;
    int r = int(arr.size());
    while (l < r)
    {
        middle = (l + r) / 2;
        if(k < arr[middle])
            r = middle;
        else
            l = middle + 1;
    }
    return r;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    fin >> n;
    vector <int> arr(n + 1);
    for(int i = 1; i <= n; i++)
        fin >> arr[i];
    vector <int> dp(n + 1);
    dp[0] = INT_MIN;
    
    for (int i = 1; i <= n; i++)
        dp[i] = INT_MAX;
    
    for (int i = 1; i <= n; i++)
        if(dp[UpperBound(dp, arr[i]) - 1] != arr[i])
            dp[UpperBound(dp, arr[i])] = arr[i];
    
    /*for (int i = n; i >= 0; i--)
    {
        if(dp[i] != INT_MAX)
        {
            cout << i << endl;
            break;
        }
    }*/
    fout << UpperBound(dp, INT_MAX - 1) - 1<< endl;
    return 0;
    
}
