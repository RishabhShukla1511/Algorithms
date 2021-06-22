class Solution
{
public:
    int dp[1001];

    int findMinCost(vector<int> &cost, int pos)
    {
        int n = cost.size();
        if (pos >= n)
            return 0;
        if (dp[pos] != -1)
            return dp[pos];
        int val1 = findMinCost(cost, pos + 1) + cost[pos];
        int val2 = findMinCost(cost, pos + 2) + cost[pos];
        return dp[pos] = min(val1, val2);
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        memset(dp, -1, sizeof(dp));
        return min(findMinCost(cost, 0), findMinCost(cost, 1));
    }
};
