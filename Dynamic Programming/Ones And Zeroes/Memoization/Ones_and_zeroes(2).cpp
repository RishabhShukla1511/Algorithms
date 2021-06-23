class Solution
{
public:
    vector<pair<int, int>> v;
    int dp[101][101][601];

    int solve(int m, int n, int pos)
    {
        if (m < 0 || n < 0)
            return -1;
        if (pos == -1)
            return 0;
        if (dp[m][n][pos] != -1)
            return dp[m][n][pos];
        int val1 = solve(m, n, pos - 1);
        int val2 = solve(m - v[pos].first, n - v[pos].second, pos - 1) + 1;
        return dp[m][n][pos] = max(val1, val2);
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {
        v.clear();
        memset(dp, -1, sizeof(dp));
        int s = strs.size();
        for (int i = 0; i < s; i++)
        {
            int z = 0, o = 0;
            for (int j = 0; j < strs[i].length(); j++)
            {
                if (strs[i][j] == '0')
                    z++;
                else
                    o++;
            }
            v.push_back({z, o});
        }
        return solve(m, n, s - 1);
    }
};