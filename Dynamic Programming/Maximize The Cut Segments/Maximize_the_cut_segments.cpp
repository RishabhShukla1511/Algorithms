#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        int arr[3];
        arr[0] = x;
        arr[1] = y;
        arr[2] = z;
        int ans[n + 1];
        memset(ans, -1, sizeof(ans));
        ans[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i - arr[j] >= 0 && ans[i - arr[j]] >= 0)
                    ans[i] = max(ans[i - arr[j]] + 1, ans[i]);
            }
        }
        return max(ans[n], 0);
    }
};

// { Driver Code Starts.
int main()
{

    //taking testcases
    int t;
    cin >> t;
    while (t--)
    {
        //taking length of line segment
        int n;
        cin >> n;

        //taking types of segments
        int x, y, z;
        cin >> x >> y >> z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout << obj.maximizeTheCuts(n, x, y, z) << endl;
    }

    return 0;
} // } Driver Code Ends