#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int maxSumIS(int arr[], int n)
    {
        // Your code goes here
        int sum[n] = {0}, maxsum = arr[n - 1];
        sum[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            int ans = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] > arr[i])
                    ans = max(ans, sum[j]);
            }
            ans += arr[i];
            sum[i] += ans;
            maxsum = max(maxsum, sum[i]);
        }
        return maxsum;
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.maxSumIS(a, n) << "\n";
    }
    return 0;
}

// } Driver Code Ends