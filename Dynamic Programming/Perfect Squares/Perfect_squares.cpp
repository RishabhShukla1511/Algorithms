class Solution
{
public:
    int dp[10001];

    int count(int n)
    {
        if (dp[n] != -1)
            return dp[n];
        int ans = n;
        for (int i = 1; i <= sqrt(n); i++)
            ans = min(ans, count(n - i * i) + 1);
        return dp[n] = ans;
    }

    int numSquares(int n)
    {
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        int ans = n;
        for (int i = 1; i <= sqrt(n); i++)
            ans = min(ans, count(n - i * i) + 1);
        return ans;
    }
};
