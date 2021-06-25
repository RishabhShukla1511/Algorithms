class Solution
{
public:
    int numWays(int steps, int arrLen)
    {
        int mod = 1000000007;
        arrLen = min(steps / 2 + 1, arrLen);
        vector<int> dp(arrLen, 0);
        dp[0] = 1;
        for (int i = 1; i <= steps; i++)
        {
            vector<int> temp(arrLen, 0);
            for (int j = 0; j < min(i + 1, arrLen); j++)
            {
                int val1 = 0, val2 = 0, val3 = 0;
                if (j - 1 >= 0)
                    val1 = dp[j - 1];
                val2 = dp[j];
                if (j + 1 < arrLen)
                    val3 = dp[j + 1];
                temp[j] = ((val1 % mod + val2 % mod) % mod + val3) % mod;
            }
            dp = temp;
        }
        return dp[0];
    }
};