class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> dp(n, 0);
        for(int i = 1; i < n; i++)
        {
            if((nums[i] & 1) ^ (nums[i - 1] & 1))
                dp[i] = dp[i - 1];
            else
                dp[i] = dp[i - 1] + 1;
        }
            
        vector<bool> res;
        for(int i = 0; i < queries.size(); i++)
            res.emplace_back(dp[queries[i][0]] == dp[queries[i][1]]);
        return res;
    }
};