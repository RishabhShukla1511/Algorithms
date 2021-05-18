#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int editDistance(string s, string t)
    {
        // Code here
        int n = s.length(), m = t.length(), dp[2][n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= n; i++)
            dp[0][i] = i;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (j == 0)
                    dp[i % 2][0] = i;
                else if (s[j - 1] == t[i - 1])
                    dp[i % 2][j] = dp[(i - 1) % 2][j - 1];
                else
                    dp[i % 2][j] = 1 + min(dp[(i - 1) % 2][j], min(dp[i % 2][j - 1], dp[(i - 1) % 2][j - 1]));
            }
        }
        return dp[m % 2][n];
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends