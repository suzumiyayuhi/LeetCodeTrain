class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        vector<string> res;
        while(left < n)
        {
            while(right + 1 < n && nums[right] + 1 == nums[right + 1])
            {
                right++;
            }
            if(left == right)
            {
                res.emplace_back(to_string(nums[left]));
                right++;
                left = right;
            }
            else
            {
                res.emplace_back(to_string(nums[left]) + "->" + to_string(nums[right]));
                right++;
                left = right;
            }
        }
        return res;
    }
};