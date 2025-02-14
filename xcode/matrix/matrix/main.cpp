#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    int s;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin >> s;
    vector<int> n(s + 1);
    vector<int> m(s + 1);
    vector<vector<int>> arr(s + 1, vector<int> (s + 1));
    for( int i = 1; i <= s; i++)
        fin >> n[i] >> m[i];
            
    for(int i = 1; i <= s; i++)
        arr[i][i] = 0;
       
    for(int i = 1; i < s; i++)
        arr[i][i + 1] = n[i] * m[i] * m[i + 1];
    
    for(int j = 3; j <= s; j++)
    {
        for(int i = j - 2; i > 0; i--)
        {
            arr[i][j] = 2147483647;
            for(int k = i; k < j; k++)
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k + 1][j] + n[i] * m[k] * m[j]);
        }
    }
    
    fout << arr[1][s];
    return 0;
}

