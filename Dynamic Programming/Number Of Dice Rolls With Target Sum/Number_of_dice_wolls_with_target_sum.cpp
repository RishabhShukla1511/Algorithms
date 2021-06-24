class Solution
{
public:
    int dp[31][1001], mod = 1000000007;

    int solve(int n, int d, int f, int target, int sum)
    {
        if (sum == target && n == d + 1)
            return 1;
        if (n > d || sum > target)
            return 0;
        if (dp[n][sum] != -1)
            return dp[n][sum];
        int ans = 0;
        for (int i = 1; i <= f; i++)
        {
            ans += solve(n + 1, d, f, target, sum + i) % mod;
            ans %= mod;
        }
        return dp[n][sum] = ans;
    }

    int numRollsToTarget(int d, int f, int target)
    {
        memset(dp, -1, sizeof(dp));
        return solve(1, d, f, target, 0);
    }
};
