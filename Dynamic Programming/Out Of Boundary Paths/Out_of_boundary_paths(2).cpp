class Solution
{
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        int dp[m][n], mod = 1000000007, cnt = 0;
        memset(dp, 0, sizeof(dp));
        dp[startRow][startColumn] = 1;
        for (int k = 1; k <= maxMove; k++)
        {
            int temp[m][n];
            memset(temp, 0, sizeof(temp));
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == 0)
                        cnt = (cnt + dp[i][j]) % mod;
                    if (j == 0)
                        cnt = (cnt + dp[i][j]) % mod;
                    if (i == m - 1)
                        cnt = (cnt + dp[i][j]) % mod;
                    if (j == n - 1)
                        cnt = (cnt + dp[i][j]) % mod;
                    temp[i][j] = (((i > 0 ? dp[i - 1][j] : 0) + (i < m - 1 ? dp[i + 1][j] : 0)) % mod +
                                  ((j > 0 ? dp[i][j - 1] : 0) + (j < n - 1 ? dp[i][j + 1] : 0)) % mod) %
                                 mod;
                }
            }
            memcpy(dp, temp, sizeof(dp));
        }
        return cnt;
    }
};
