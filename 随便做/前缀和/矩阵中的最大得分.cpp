class Solution {
public:
/*
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
        int res =INT_MIN;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                dp[i][j] = min(grid[i - 1][j - 1], dp[i - 1][j]);
                dp[i][j] = min(dp[i][j], dp[i][j - 1]);
                res = max(grid[i - 1][j - 1] - dp[i - 1][j], res);
                res = max(grid[i - 1][j - 1] - dp[i][j - 1], res);
            }
        }
        return res;
    }
    */
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> colMin(m + 1, INT_MAX);
        int res =INT_MIN;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                res = max(res, grid[i - 1][j - 1] - min(colMin[j], colMin[j - 1]));
                colMin[j] = min(min(colMin[j], colMin[j - 1]), grid[i - 1][j - 1]);
            }
            
        }
        return res;
    }
};