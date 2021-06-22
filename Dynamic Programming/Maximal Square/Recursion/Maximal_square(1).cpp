class Solution
{
public:
    int solve(vector<vector<char>> &matrix, int x, int y)
    {
        int m = matrix.size(), n = matrix[0].size();
        for (int k = 2; k <= min(m - x, n - y); k++)
        {
            int d = x + k - 1, r = y + k - 1;
            for (int a = x, b = y; a <= d, b <= r; a++, b++)
            {
                if (matrix[a][r] == '0' || matrix[d][b] == '0')
                    return k - 1;
            }
        }
        return min(m - x, n - y);
    }

    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                    ans = max(ans, solve(matrix, i, j));
            }
        }
        return ans * ans;
    }
};