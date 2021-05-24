#include <bits/stdc++.h>
using namespace std;

int subsetSum(int arr[], int n, int sum)
{
    bool dp[n + 1][sum + 1];
    for (int i = 0; i < sum + 1; i++)
        dp[0][i] = false;
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = true;
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
    for (int j = 0; j <= sum / 2; j++)
    {
        if (dp[n][j])
            ans = min(ans, abs(sum - 2 * j));
    }
    return ans;
}

int minSubsetSumDiff(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return subsetSum(arr, n, sum);
}

int main()
{
    int n;
    cout << "Enter the length of array\n";
    cin >> n;
    int arr[n];
    cout << "Enter the array\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Minimum Subset Sum Difference = " << minSubsetSumDiff(arr, n);
}