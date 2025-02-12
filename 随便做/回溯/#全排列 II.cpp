class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temRes;
        vector<vector<int>> res;
        vector<int> selected(nums.size(), 0);
        sub(res, nums, temRes, 0, selected);
        return res;
    }

    void sub(vector<vector<int>>& res, vector<int>& nums, vector<int>& temRes, int cur, vector<int>& selected)
    {
        if(temRes.size() == nums.size())
        {
            res.emplace_back(temRes);
            return;
        }

        for(int i = 0; i <nums.size(); i++)
        {
            if(selected[i])
                continue;
            //if(i > cur && nums[i] == nums[i - 1])
            if(i > 0 && nums[i] == nums[i - 1] && !selected[i - 1])
                continue;
            temRes.emplace_back(nums[i]);
            selected[i] = 1;
            sub(res, nums, temRes, cur + 1, selected);
            selected[i] = 0;
            temRes.pop_back();
        }

    }
};