#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);
    std::string s;
    std::cin >> s;
    std::vector < std::vector <int> > dp(s.size());
    for (int i = 0; i < s.size(); ++i)
    {
        dp[i].resize(s.size() - i);
        dp[i][0] = 1;
    }
    for (int i = 0; i < s.size() - 1; ++i)
        if (s[i] == s[i + 1])
            dp[i][1] = 2;
        else
            dp[i][1] = 1;
    for (int j = 2; j < dp.size(); ++j)
        for (int i = 0; i < s.size() - j; i++)
            if (s[i] == s[i + j])
                dp[i][j] = dp[i + 1][j - 2] + 2;
            else
                dp[i][j] = std::max(dp[i][j - 1], dp[i + 1][j - 1]);
    std::string minPalindrome;
    int l = 0, r = s.size() - 1;
    std::string sub1, sub2;
    while (r >= 0)
    {
        if (s[l] == s[l + r])
        {
            minPalindrome += s[l];
            l++; r-= 2;
        }
        else
        {
            if (dp[l][r - 1] > dp[l + 1][r - 1])
                r--;
            else
                if (dp[l][r - 1] < dp[l + 1][r - 1])
                {
                    l++; r--;
                }
                else
                {
                    sub1 = s.substr(l, r);
                    sub2 = s.substr(l + 1, r);
                    if (sub1 < sub2)
                        r--;
                    else
                    {
                        l++; r--;
                    }
                }
        }
    }
    std::string temp = minPalindrome.substr(0, dp[0][s.size() - 1] / 2);
    reverse(temp.begin(), temp.end());
    minPalindrome += temp;
    std::cout << minPalindrome << '\n';
    std::string maxPalindrome;
    l = 0, r = s.size() - 1;
    while (l >= 0 && r >= 0)
    {
        if (s[l] == s[l + r])
        {
            maxPalindrome += s[l];
            l++; r-= 2;
        }
        else
        {
            if (dp[l][r - 1] > dp[l + 1][r - 1])
                r--;
            else
                if (dp[l][r - 1] < dp[l + 1][r - 1])
                {
                    l++; r--;
                }
                else
                {
                    sub1 = s.substr(l, r);
                    sub2 = s.substr(l + 1, r);
                    std::cout << "s1" << sub1 << '\n' << "s2" << sub2 << '\n';
                    if (sub1 > sub2)
                        r--;
                    else
                    {
                        l++; r--;
                    }
                }
        }
    }
    temp = maxPalindrome.substr(0, dp[0][s.size() - 1] / 2);
    reverse(temp.begin(), temp.end());
    maxPalindrome += temp;
    std::cout << maxPalindrome << '\n';
    return 0;
}
