#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    void binarySearch(vector<int> &dp, int val)
    {
        if (dp.size() == 0 || dp[dp.size() - 1] < val)
        {
            dp.push_back(val);
            return;
        }
        int l = 0, h = dp.size() - 1;
        while (l < h)
        {
            int mid = l + (h - l) / 2;
            if (dp[mid] < val)
                l = mid + 1;
            else if (dp[mid] > val)
                h = mid;
            else
                return;
        }
        dp[l] = val;
        return;
    }

    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        // your code here
        vector<int> dp;
        for (int i = 0; i < n; i++)
            binarySearch(dp, a[i]);
        return dp.size();
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        //taking size of array
        cin >> n;
        int a[n];

        //inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
// } Driver Code Ends