class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        int i = 0;
        sort(nums.begin(), nums.end());
        for(int j = (n + 1) / 2; j < n; j++)
        {
            if(2 * nums[i] <= nums[j])
            {
                res++;
                i++;
            }
        }
        return res * 2;
    }
};