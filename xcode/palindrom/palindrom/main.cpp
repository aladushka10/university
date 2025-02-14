#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int main() {
    //ifstream fin("input.txt");
    //ofstream fout("output.txt");
    string s;
    cin >> s;
    vector <vector<int>> dp(s.size(), vector<int> (s.size()));
    for(int i = 0; i < s.size(); i++)
        dp[i][i] = 1;
    for(int j = 1; j < s.size(); j++)
    {
        for(int i = j - 1; i >= 0; i--)
        {
                if(s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    int k = dp[0][s.size() - 1];
    cout << k << endl;
    
    int i = 0, j = int(s.size()) - 1;
    string palindrom = "";
    while (i <= j)
    {
        if (s[i] == s[j])
        {
            palindrom += s[i];
            i++;
            j--;
        }
        else
            if (dp[i + 1][j] >= dp[i][j - 1])
                i++;
            else
                j--;
    }
    if(k % 2 == 0)
    {
        cout << palindrom;
        for(int i = int(palindrom.size()) - 1; i >= 0; i--)
            cout << palindrom[i];
        cout << endl;
    }
    else
    {
        cout << palindrom;
        for(int i = int(palindrom.size()) - 2; i >= 0; i--)
            cout << palindrom[i];
        cout << endl;
    }
    return 0;
}
