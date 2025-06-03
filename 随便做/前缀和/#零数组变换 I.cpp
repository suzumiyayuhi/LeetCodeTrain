class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1);
        for(int i = 0; i < queries.size(); i++)
        {
            diff[queries[i][0]]++;
            diff[queries[i][1] + 1]--;
        }
        
        int prefixSum = 0;
        for(int i = 0; i < n; i++)
        {
            prefixSum += diff[i];
            if(nums[i] > prefixSum)
                return false;
        }
        return true;
    }
};