// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int maxgold[n][m], ans = 0;
        for (int j = m - 1; j >= 0; j--)
        {
            for (int i = 0; i < n; i++)
            {
                if (j == m - 1)
                    maxgold[i][j] = M[i][j];
                else
                {
                    int rup = 0, r = 0, rdown = 0;
                    if (i - 1 >= 0 && j + 1 < m)
                        rup = maxgold[i - 1][j + 1];
                    if (j + 1 < m)
                        r = maxgold[i][j + 1];
                    if (i + 1 < n && j + 1 < m)
                        rdown = maxgold[i + 1][j + 1];
                    maxgold[i][j] = M[i][j] + max(rup, max(r, rdown));
                }
                if (j == 0)
                    ans = max(ans, maxgold[i][0]);
            }
        }
        return ans;
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
        vector<vector<int>> M(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> M[i][j];
        }

        Solution ob;
        cout << ob.maxGold(n, m, M) << "\n";
    }
    return 0;
} // } Driver Code Ends