class Solution
{
public:
    int dp[101][101];

    int solve(int x, int y, int m, int n, vector<vector<int>> &obstacleGrid)
    {
        if (x == m - 1 && y == n - 1 && obstacleGrid[x][y] == 0)
            return 1;
        if (x >= m || x < 0 || y < 0 || y >= n)
            return 0;
        if (obstacleGrid[x][y] == 1)
            return 0;
        if (dp[x][y] != -1)
            return dp[x][y];
        return dp[x][y] = solve(x + 1, y, m, n, obstacleGrid) + solve(x, y + 1, m, n, obstacleGrid);
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, m, n, obstacleGrid);
    }
};