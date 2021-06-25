class Solution
{
public:
    map<pair<int, int>, int> m;
    int mod = 1000000007;

    int solve(int pos, int n, int steps)
    {
        if (pos == -1 || pos == n || pos > steps)
            return 0;
        if (steps == 0 && pos == 0)
            return 1;
        if (m.find({pos, steps}) != m.end())
            return m[{pos, steps}];
        return m[{pos, steps}] = ((solve(pos + 1, n, steps - 1) % mod + solve(pos, n, steps - 1) % mod) % mod + solve(pos - 1, n, steps - 1) % mod) % mod;
    }

    int numWays(int steps, int arrLen)
    {
        return solve(0, arrLen, steps);
    }
};