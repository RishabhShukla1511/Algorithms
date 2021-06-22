class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int a = cost[0], b = cost[1], n = cost.size();
        for (int i = 2; i < n; i++)
        {
            int t = cost[i] + min(a, b);
            a = b;
            b = t;
        }
        return min(a, b);
    }
};