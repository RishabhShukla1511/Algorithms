#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int mini(int a, int b, int c)
    {
        return min(a, min(b, c));
    }

    int minDistance(string str1, string str2, int pos1, int pos2, vector<vector<int>> &v)
    {
        if (v[pos1][pos2] != -1)
            return v[pos1][pos2];
        int n = str1.length(), m = str2.length();
        if (pos1 >= n)
            return m - pos2;
        if (pos2 >= m)
            return n - pos1;
        if (str1[pos1] == str2[pos2])
            v[pos1][pos2] = minDistance(str1, str2, pos1 + 1, pos2 + 1, v);
        else
            v[pos1][pos2] = 1 + mini(minDistance(str1, str2, pos1, pos2 + 1, v), minDistance(str1, str2, pos1 + 1, pos2, v), minDistance(str1, str2, pos1 + 1, pos2 + 1, v));
        return v[pos1][pos2];
    }

    int editDistance(string s, string t)
    {
        // Code here
        int n = s.length(), m = t.length();
        vector<vector<int>> v;
        vector<int> temp(m + 1, -1);
        for (int i = 0; i <= n; i++)
            v.push_back(temp);
        return minDistance(s, t, 0, 0, v);
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends