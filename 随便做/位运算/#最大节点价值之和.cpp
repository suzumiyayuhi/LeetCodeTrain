class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            res += nums[i];
        }

        vector<int> diff(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++)
        {
            diff[i] = (nums[i] ^ k) - nums[i];
        }

        for(int i = diff.size() - 1; i > 0; i -= 2)
        {
            res += max(0, diff[i] + diff[i - 1]);
        }
        /*
        sort(diff.begin(), diff.end());
        for (int i = diff.size() - 1; i > 0 && diff[i] + diff[i - 1] >= 0;
             i -= 2) {
            res += max(0, diff[i] + diff[i - 1]);
        }
        */
        return res;
    }
};