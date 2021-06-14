#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int dp[2][1001];

    int LCS(string str1, string str2)
    {
        int n = str1.length();
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                    dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
                else
                    dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
            }
        }
        return dp[n % 2][n];
    }

    int LPS(string str)
    {
        string org = str;
        reverse(str.begin(), str.end());
        return LCS(org, str);
    }

    int minimumNumberOfDeletions(string S)
    {
        // code here
        return S.length() - LPS(S);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
} // } Driver Code Ends