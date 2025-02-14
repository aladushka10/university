#include <iostream>
#include <vector>
using namespace std;

int m = 1e9 + 7;

long long binpow (int a, int p) {
    if (p == 0)
        return 1;
    if (p % 2 == 1)
        return (binpow(a, p - 1) * a) % m;
    else {
        long long b = binpow (a, p / 2);
        return (b * b) % m;
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector <long long> dp(k + 1);
    
    dp[0] = 1;

    for(int i = 1; i <= k; i++)
        dp[i] = ((dp[i - 1] * (n - i + 1)) % m * binpow(i, m - 2)) % m;
    cout << dp[k] << endl;
    return 0;
}
