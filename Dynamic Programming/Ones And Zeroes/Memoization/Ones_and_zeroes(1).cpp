class Solution
{
public:
    int dp[101][101];

    int countZero(string str)
    {
        int cnt = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '0')
                cnt++;
        }
        return cnt;
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {
        memset(dp, 0, sizeof(dp));
        for (string str : strs)
        {
            int z = countZero(str), o = str.length() - z;
            for (int i = m; i >= z; i--)
            {
                for (int j = n; j >= o; j--)
                    dp[i][j] = max(dp[i - z][j - o] + 1, dp[i][j]);
            }
        }
        return dp[m][n];
    }
};