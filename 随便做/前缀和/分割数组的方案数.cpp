class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long prefix = 0;
        long long total = 0;
        for(int i = 0; i < n; i++)
        {
            total += nums[i];
        }

        int res = 0;
        for(int i = 0; i < n - 1; i++)
        {
            prefix += nums[i];
            if(prefix >= total - prefix)
                res++;
        }
        return res;
    }
};
