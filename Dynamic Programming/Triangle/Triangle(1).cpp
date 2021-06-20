class Solution
{
public:
    vector<vector<int>> dp;

    int traverse(vector<vector<int>> &triangle, int x, int y)
    {
        int n = triangle.size();
        if (x == n - 1)
            return triangle[x][y];
        if (dp[x][y] != INT_MIN)
            return dp[x][y];
        int left = traverse(triangle, x + 1, y) + triangle[x][y];
        int right = traverse(triangle, x + 1, y + 1) + triangle[x][y];
        return dp[x][y] = min(left, right);
    }

    int minimumTotal(vector<vector<int>> &triangle)
    {
        dp = triangle;
        for (int i = 0; i < dp.size(); i++)
            fill(dp[i].begin(), dp[i].end(), INT_MIN);
        return traverse(triangle, 0, 0);
    }
};