class Solution
{
public:
    int dp[201][201];

    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        memset(dp, 40000, sizeof(dp));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != m - 1)
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + grid[i + 1][j]);
                if (j != n - 1)
                    dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + grid[i][j + 1]);
            }
        }
        return dp[m - 1][n - 1];
    }
};