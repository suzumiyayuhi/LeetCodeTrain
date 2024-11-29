class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n, vector<int>(51, 0));

        for(int v = 0; v <= nums[0]; v++)
        {
            dp[0][v] = 1;
        }

        for(int i = 1; i < n; i++)
        {
            for(int v2 = 0; v2 <= nums[i]; v2++)
            {
                for(int v1 = 0; v1 <= v2; v1++)
                {
                    if (nums[i - 1] - v1 >= nums[i] - v2 && nums[i] - v2 >= 0)
                        dp[i][v2] = (dp[i - 1][v1] + dp[i][v2]) % mod;
                }
            }
        }
        int res = 0;
        for(int i = 0; i < 51; i++)
        {
            res = (res + dp[n - 1][i]) % mod;
        }
        return res;
    }
};