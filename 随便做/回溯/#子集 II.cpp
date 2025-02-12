class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        vector<int> temRes;
        sub(res, nums, temRes, 0);
        return res;
    }

    void sub(vector<vector<int>>& res, vector<int>& nums, vector<int>& temRes, int cur)
    {
        res.emplace_back(temRes);

        for(int i = cur; i < nums.size(); i++)
        {
            if(i > cur && nums[i] == nums[i - 1])
                continue;
            temRes.emplace_back(nums[i]);
            sub(res, nums, temRes, i + 1);
            temRes.pop_back();
        }
    }
};