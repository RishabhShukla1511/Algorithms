class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size(), arr[n], lislen = 1;
        for (int i = 0; i < n; i++)
            arr[i] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            int ans = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] > nums[i])
                    ans = max(ans, arr[j] + 1);
            }
            arr[i] = ans;
            lislen = max(lislen, ans);
        }
        return lislen;
    }
};
