#include <bits/stdc++.h>
using namespace std;

int subsetsNumwithDiff(int arr[], int n, int diff)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    int dp[n + 1][sum + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 1;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][(sum + diff) / 2];
}

int main()
{
    int n;
    cout << "Enter the length of array\n";
    cin >> n;
    int arr[n];
    cout << "Enter the numbers(positive)\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int diff;
    cout << "Enter the difference\n";
    cin >> diff;
    cout << "Number of subsets having difference = " << diff << " are " << subsetsNumwithDiff(arr, n, diff);
}