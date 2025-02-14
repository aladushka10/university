#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <vector<int>> dp(n + 1, vector<int> (n + 1));
    vector<int> A(n + 1);
    vector<int> B(n + 1);
    
    for(int i = 1; i <= n; i++)
        cin >> A[i];
    for(int i = 1; i <= n; i++)
        cin >> B[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(A[i] == B[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[n][n] << endl;
    
    vector <int> arrA;
    vector <int> arrB;

    int i = n, j = n;
    while(i > 0 && j > 0)
    {
        if(A[i] == B[j])
        {
            arrA.push_back(i);
            arrB.push_back(j);
            i--;
            j--;
        }
        else
            if(dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
    }
    
    for(int i = int(arrA.size()) - 1; i >= 0; i--)
        cout << arrA[i] << " ";
    cout << endl;
    for(int i = int(arrB.size()) - 1; i >= 0; i--)
        cout << arrB[i] << " ";
    return 0;
}

