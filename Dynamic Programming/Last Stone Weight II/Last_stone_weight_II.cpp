class Solution
{
public:
    int lastStoneWeightII(vector<int> &arr)
    {
        int n = arr.size(), sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];
        bool dp[n + 1][sum + 1];
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
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
        }
        int ans = sum;
        for (int i = 0; i <= sum; i++)
        {
            if (dp[n][i])
                ans = min(ans, abs(sum - 2 * i));
        }
        return ans;
    }
};