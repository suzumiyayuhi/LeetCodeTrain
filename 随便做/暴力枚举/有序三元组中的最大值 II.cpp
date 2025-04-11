class Solution {
public:
    /*
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        for(int k = 2; k < n; k++)
        {
            int i = nums[0];
            for(int j = 1; j < k; j++)
            {
                res = max(res, (long long)(i - nums[j]) * (long long)nums[k]);
                i = max(i, nums[j]);
            }
        }
        return res;
    }
    */

    long long maximumTripletValue(vector<int>& nums)
    {
        int n = nums.size();
        long long res = 0, dmax = 0, imax = 0;
        for(int k = 2; k < n; k++)
        {
            imax = max(imax, (long long)nums[k - 2]);
            dmax = max(dmax, imax - (long long)nums[k - 1]);
            res = max(res, dmax * (long long)nums[k]);
        }
        return res;
    }
};