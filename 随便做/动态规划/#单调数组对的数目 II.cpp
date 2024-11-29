class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(1001, 0));

        for(int v = 0; v <= nums[0]; v++)
        {
            dp[0][v] = 1;
        }

        for(int i = 1; i < n; i++)
        {
            int d = max(0, nums[i] - nums[i - 1]);
            for(int v = d; v <= nums[i]; v++)
            {
                if(v)
                    dp[i][v] = (dp[i - 1][v - d] + dp[i][v - 1]) % mod;
                else
                    dp[i][v] = dp[i - 1][v - d];
            }
        }
        int res = 0;
        for(int i = 0; i < 1001; i++)
        {
            res = (res + dp[n - 1][i]) % mod;
        }
        return res;
    }
};