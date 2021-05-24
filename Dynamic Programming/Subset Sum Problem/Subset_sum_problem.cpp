#include <bits/stdc++.h>
using namespace std;

bool hasSubsetwithgivenSum(int arr[], int n, int sum)
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

int main()
{
    int n;
    cout << "Enter the length of the array\n";
    cin >> n;
    int arr[n];
    cout << "Enter the numbers(non negative)\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] < 0)
        {
            cout << "Invalid entry\n";
            return 0;
        }
    }
    int sum;
    cout << "Enter the value of sum required\n";
    cin >> sum;
    if (hasSubsetwithgivenSum(arr, n, sum))
        cout << "Yes, there is a subset in the array with sum = " << sum;
    else
        cout << "No, there is no subset in the array with sum = " << sum;
    return 0;
}