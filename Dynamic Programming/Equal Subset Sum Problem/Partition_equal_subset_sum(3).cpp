class Solution
{
public:
    bool hasSubsetwithgivenSum(vector<int> arr, int n, int sum)
    {
        int dp[n + 1][sum + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0)
                    dp[0][j] = false;
                if (j == 0)
                    dp[i][0] = true;
            }
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (arr[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i - 1][j - arr[i - 1]], dp[i - 1][j]);
            }
        }
        return dp[n][sum];
    }

    bool canPartition(vector<int> &nums)
    {
        int sum = 0, n = nums.size();
        for (int i = 0; i < n; i++)
            sum += nums[i];
        if (sum % 2 != 0)
            return false;
        return hasSubsetwithgivenSum(nums, n, sum / 2);
    }
};