class Solution
{
public:
    int dp[1001][1001];

    int solve(int textlen, int copylen, int req)
    {
        if (textlen > req)
            return 1001;
        if (textlen == req)
            return 0;
        if (dp[textlen][copylen] != -1)
            return dp[textlen][copylen];
        int val1 = solve(textlen + copylen, copylen, req) + 1;
        int val2 = solve(2 * textlen, textlen, req) + 2;
        return dp[textlen][copylen] = min(val1, val2);
    }

    int minSteps(int n)
    {
        memset(dp, -1, sizeof(dp));
        if (n == 1)
            return 0;
        return solve(2, 1, n) + 2;
    }
};