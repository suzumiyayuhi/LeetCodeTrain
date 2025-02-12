class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<int> dp(m, 0);
        if(obstacleGrid[0][0] == 1)
            return 0;
        dp[0] = 1;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    dp[j] = 0;
                    continue;
                }
                if(j - 1 >= 0 && obstacleGrid[i][j - 1] == 0)
                    dp[j] += dp[j - 1];
            }
        }
        return dp[m - 1];
    }
    

};