//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    int LCS(char *str1, char *str2, int n, int m)
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
        return dp[n][m];
    }

    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(char *X, char *Y, int m, int n)
    {
        //code here
        return n + m - LCS(X, Y, m, n);
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    char X[10001], Y[10001];

    //taking total testcases
    cin >> t;
    while (t--)
    {

        //taking String X and Y
        cin >> X >> Y;

        //calling function shortestCommonSupersequence()
        Solution obj;
        cout << obj.shortestCommonSupersequence(X, Y, strlen(X), strlen(Y)) << endl;
    }
    return 0;
}

// } Driver Code Ends