class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size(), arr[n], cnt[n], num = 1;
        for (int i = 0; i < n; i++)
        {
            arr[i] = 1;
            cnt[i] = 0;
        }
        cnt[n - 1] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            int ans = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] > nums[i])
                    ans = max(ans, arr[j] + 1);
            }
            arr[i] = ans;
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] > nums[i] && arr[j] == arr[i] - 1)
                    cnt[i] += cnt[j];
            }
            if (cnt[i] == 0)
                cnt[i] = 1;
            num = max(num, arr[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == num)
                ans += cnt[i];
        }
        return ans;
    }
};
