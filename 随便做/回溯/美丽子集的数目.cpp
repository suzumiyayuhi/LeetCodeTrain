class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> um;
        int res = 0;
        sub(nums, k, 0, um, res);
        return res - 1;
    }

    void sub(vector<int>& nums, int k, int index, unordered_map<int, int>& um, int& res)
    {
        if(index == nums.size())
        {
            res++;
            return;
        }
        sub(nums, k, index + 1, um, res);
        if(um[nums[index] - k] == 0 && um[nums[index] + k] == 0)
        {
            um[nums[index]]++;
            sub(nums, k, index + 1, um, res);
            um[nums[index]]--;
        }
    }
};