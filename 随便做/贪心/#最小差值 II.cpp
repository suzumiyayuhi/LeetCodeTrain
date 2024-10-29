class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n == 1)
            return 0;

        int temMax = nums[n - 1] - k, temMin = nums[0] + k;
        int newMax = temMax, newMin = temMin;
        int res = nums[n - 1] - nums[0];
        /*
        for(int i = 1; i < n; i++)
        {
            if(nums[i] - k <= temMin)
                newMin = nums[i] - k;
            else
                break;
        }
        for(int i = n - 2; i >= 0; i--)
        {
            if(nums[i] + k >= temMax)
                newMax = nums[i] + k;
            else
                break;
        }
        */
        for(int i = 1; i < n; i++)
        {
            newMax = max(temMax, nums[i - 1] + k);
            newMin = min(temMin, nums[i] - k);
            res = min(res, newMax - newMin);
        }
        return res;
    }
};