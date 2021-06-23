class Solution
{
public:
    int dp[46];

    int solve(int curr, int n)
    {
        if (curr > n)
            return 0;
        if (dp[curr] != -1)
            return dp[curr];
        return dp[curr] = solve(curr + 1, n) + solve(curr + 2, n);
    }

    int climbStairs(int n)
    {
        memset(dp, -1, sizeof(dp));
        dp[n] = 1;
        return solve(0, n);
    }
};