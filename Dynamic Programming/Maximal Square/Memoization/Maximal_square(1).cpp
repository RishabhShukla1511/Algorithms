class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size(), dp[m + 1][n + 1], ans = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (matrix[i - 1][j - 1] == '1')
                {
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans * ans;
    }
};