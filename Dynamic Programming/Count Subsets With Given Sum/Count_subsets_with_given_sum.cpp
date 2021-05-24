#include <bits/stdc++.h>
using namespace std;

int subsetsNum(int arr[], int n, int sum)
{
    int dp[n + 1][sum + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < sum + 1; i++)
        dp[0][i] = 0;
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 1;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
        }
    }
    return dp[n][sum];
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
    int sum;
    cout << "Enter the sum\n";
    cin >> sum;
    cout << "Number of subsets having sum = " << sum << " are: " << subsetsNum(arr, n, sum);
}