#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int wt[], int val[], int n, int W)
{
    int dp[n + 1][W + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
            {
                if (wt[i - 1] <= j)
                    dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}

int main()
{
    int n;
    cout << "Enter the number of items\n";
    cin >> n;
    int wt[n], val[n];
    cout << "Enter the weight of items\n";
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    cout << "Enter the value of items\n";
    for (int i = 0; i < n; i++)
        cin >> val[i];
    int W;
    cout << "Enter the weight of knapsack\n";
    cin >> W;
    cout << "Maximum possible value = " << unboundedKnapsack(wt, val, n, W);
}