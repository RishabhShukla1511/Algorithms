#include <bits/stdc++.h>
using namespace std;

string printLCS(string str1, string str2, int n, int m)
{
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string lcs = "";
    int x = n, y = m;
    while (x != 0 && y != 0)
    {
        if (str1[x - 1] == str2[y - 1])
        {
            lcs += str1[x - 1];
            x--;
            y--;
        }
        else
        {
            if (dp[x - 1][y] > dp[x][y - 1])
                x--;
            else
                y--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main()
{
    string str1, str2;
    cout << "Enter the first string\n";
    cin >> str1;
    cout << "Enter the second string\n";
    cin >> str2;
    cout << "Longest Common Subsequence among " << str1 << " and " << str2 << " is " << printLCS(str1, str2, str1.length(), str2.length());
}