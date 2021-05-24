class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0, n = nums.size(), cnt = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (nums[i] == 0)
                cnt++;
        }
        if (sum < target || (sum + target) % 2 != 0)
            return 0;
        sum = (sum + target) / 2;
        int dp[n + 1][sum + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n + 1; i++)
            dp[i][0] = 1;
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (nums[i - 1] > j || nums[i - 1] == 0)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
            }
        }
        return dp[n][sum] * pow(2, cnt);
    }
};