class Solution
{
public:
    int dp[51][51][51], mod = 1000000007;

    int solve(int m, int n, int maxmove, int x, int y)
    {
        if (x < 0 || x == m || y < 0 || y == n)
            return 1;
        if (maxmove == 0)
            return 0;
        if (dp[maxmove][x][y] != -1)
            return dp[maxmove][x][y];
        dp[maxmove][x][y] = ((solve(m, n, maxmove - 1, x - 1, y) + solve(m, n, maxmove - 1, x, y - 1)) % mod + (solve(m, n, maxmove - 1, x + 1, y) + solve(m, n, maxmove - 1, x, y + 1)) % mod) % mod;
        return dp[maxmove][x][y];
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        memset(dp, -1, sizeof(dp));
        return solve(m, n, maxMove, startRow, startColumn);
    }
};