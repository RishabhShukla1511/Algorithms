class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size(), dp[n + 1], ans = 0, prev = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int temp = dp[j];
                if (matrix[i - 1][j - 1] == '1')
                {
                    dp[j] = 1 + min(dp[j], min(dp[j - 1], prev));
                    ans = max(ans, dp[j]);
                }
                else
                    dp[j] = 0;
                prev = temp;
            }
        }
        return ans * ans;
    }
};