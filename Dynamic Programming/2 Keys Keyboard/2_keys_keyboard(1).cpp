class Solution
{
public:
    int solve(int textlen, int copylen, int req)
    {
        if (textlen > req)
            return 1001;
        if (textlen == req)
            return 0;
        int val1 = solve(textlen + copylen, copylen, req) + 1;
        int val2 = solve(2 * textlen, textlen, req) + 2;
        // cout << textlen << " " << copylen << " " << val1 << " " << val2 << " " << val3 << '\n';
        return min(val1, val2);
    }

    int minSteps(int n)
    {
        if (n == 1)
            return 0;
        return solve(2, 1, n) + 2;
    }
};