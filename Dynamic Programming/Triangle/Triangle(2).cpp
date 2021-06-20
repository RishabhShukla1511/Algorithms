class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size(), dp[2][n], ans = 2000000;
        for (int i = 1; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
                dp[i][j] = ans;
        }
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i + 1; j++)
            {
                int a = ans, b = ans;
                if (j - 1 >= 0)
                    a = dp[(i - 1) % 2][j - 1] + triangle[i][j];
                if (j <= i - 1)
                    b = dp[(i - 1) % 2][j] + triangle[i][j];
                dp[i % 2][j] = min(a, b);
            }
        }
        for (int j = 0; j < n; j++)
            ans = min(ans, dp[(n - 1) % 2][j]);
        return ans;
    }
};