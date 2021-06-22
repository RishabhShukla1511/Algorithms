class Solution
{
public:
    int minSteps(int n)
    {
        if (n == 1)
            return 0;
        int cnt = 0, curr = 1, prev = 0;
        while (curr < n)
        {
            int rest = n - curr;
            if (rest % curr == 0)
            {
                prev = curr;
                curr *= 2;
                cnt += 2;
            }
            else
            {
                curr += prev;
                cnt++;
            }
        }
        return cnt;
    }
};