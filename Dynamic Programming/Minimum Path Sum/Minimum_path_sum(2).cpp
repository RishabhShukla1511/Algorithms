class Solution
{
public:
    int dp[201][201];

    int traverse(vector<vector<int>> &grid, int x, int y)
    {
        int m = grid.size(), n = grid[0].size();
        if (x == m - 1 && y == n - 1)
            return grid[x][y];
        if (dp[x][y] != -1)
            return dp[x][y];
        int down = 40000, right = down;
        if (x + 1 < m)
            down = traverse(grid, x + 1, y) + grid[x][y];
        if (y + 1 < n)
            right = traverse(grid, x, y + 1) + grid[x][y];
        return dp[x][y] = min(right, down);
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        memset(dp, -1, sizeof(dp));
        return traverse(grid, 0, 0);
    }
};