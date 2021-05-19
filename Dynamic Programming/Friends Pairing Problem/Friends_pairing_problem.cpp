#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int countFriendsPairings(int n)
    {
        // code here
        if (n < 3)
            return n;
        long long a = 1, b = 2, mod = 1000000007;
        for (int i = 3; i <= n; i++)
        {
            long long ans = (b + ((i - 1) * a) % mod) % mod;
            a = b;
            b = ans;
        }
        return b;
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
        Solution ob;
        cout << ob.countFriendsPairings(n);
        cout << endl;
    }
}
// } Driver Code Ends