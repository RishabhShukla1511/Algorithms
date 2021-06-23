class Solution
{
public:
    vector<pair<int, int>> v;

    int solve(vector<string> &strs, int m, int n, int pos)
    {
        if (m < 0 || n < 0)
            return -1;
        if (pos == -1)
            return 0;
        int val1 = solve(strs, m, n, pos - 1);
        int val2 = solve(strs, m - v[pos].first, n - v[pos].second, pos - 1) + 1;
        return max(val1, val2);
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {
        v.clear();
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
        return solve(strs, m, n, s - 1);
    }
};