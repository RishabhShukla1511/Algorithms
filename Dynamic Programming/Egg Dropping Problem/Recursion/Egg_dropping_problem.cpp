#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find minimum number of attempts needed in
    //order to find the critical floor.
    int eggDrop(int n, int k)
    {
        // your code here
        if (k < 2 || n == 1)
            return k;
        int attempts = k;
        for (int i = 1; i <= k; i++)
            attempts = min(attempts, 1 + max(eggDrop(n - 1, i - 1), eggDrop(n, k - i)));
        return attempts;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //taking eggs and floors count
        int n, k;
        cin >> n >> k;
        Solution ob;
        //calling function eggDrop()
        cout << ob.eggDrop(n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends