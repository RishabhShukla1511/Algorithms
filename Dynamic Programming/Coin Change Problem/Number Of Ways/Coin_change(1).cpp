#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int coinchange(int S[], int m, int n, vector<vector<long long>> &v)
    {
        //code here.
        if (n == 0)
            v[m][n] = 1;
        if (n < 0 || (m <= 0 && n >= 1))
            return 0;
        if (v[m][n] != -1)
            return v[m][n];
        v[m][n] = coinchange(S, m - 1, n, v) + coinchange(S, m, n - S[m - 1], v);
        return v[m][n];
    }

    long long int count(int S[], int m, int n)
    {
        //code here.
        vector<vector<long long>> v;
        vector<long long> temp(n + 1, -1);
        for (long i = 0; i <= m; i++)
            v.push_back(temp);
        return coinchange(S, m, n, v);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
} // } Driver Code Ends