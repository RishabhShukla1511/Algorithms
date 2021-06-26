class Solution
{
public:
    int dp[4][3][5001], mod = 1000000007;

    int solve(int x, int y, vector<vector<char>> &numPad, int cnt)
    {
        if (x < 0 || x >= 4 || y < 0 || y >= 3)
            return 0;
        if (numPad[x][y] == '*' || numPad[x][y] == '#')
            return 0;
        if (cnt == 0)
            return dp[x][y][cnt] = 1;
        if (dp[x][y][cnt] != -1)
            return dp[x][y][cnt];
        int ans =
            (((solve(x - 2, y - 1, numPad, cnt - 1) % mod +
               solve(x - 2, y + 1, numPad, cnt - 1) % mod) %
                  mod +
              (solve(x - 1, y - 2, numPad, cnt - 1) % mod +
               solve(x - 1, y + 2, numPad, cnt - 1) % mod) %
                  mod) %
                 mod +
             ((solve(x + 1, y - 2, numPad, cnt - 1) % mod +
               solve(x + 1, y + 2, numPad, cnt - 1) % mod) %
                  mod +
              (solve(x + 2, y - 1, numPad, cnt - 1) % mod +
               solve(x + 2, y + 1, numPad, cnt - 1) % mod) %
                  mod) %
                 mod) %
            mod;
        return dp[x][y][cnt] = ans % mod;
    }

    int knightDialer(int n)
    {
        memset(dp, -1, sizeof(dp));
        vector<vector<char>> numPad{
            {'1', '2', '3'},
            {'4', '5', '6'},
            {'7', '8', '9'},
            {'*', '0', '#'}};
        int ans = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (numPad[i][j] == '*' || numPad[i][j] == '#')
                    continue;
                ans += solve(i, j, numPad, n - 1) % mod;
                ans %= mod;
            }
        }
        return ans;
    }
};