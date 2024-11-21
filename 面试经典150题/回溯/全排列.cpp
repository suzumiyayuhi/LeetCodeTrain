class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int> cur;
        vector<int> selected(nums.size(), 0);
        sub(nums, cur, res, selected);
        return res;
    }

    void sub(vector<int>& nums, vector<int> &cur, vector<vector<int>>& res, vector<int>& selected)
    {
        if(cur.size() == nums.size())
        {
            res.emplace_back(cur);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(selected[i])
                continue;
            cur.emplace_back(nums[i]);
            selected[i] = 1;
            sub(nums, cur, res, selected);
            selected[i] = 0;
            cur.erase(cur.end());
        }
    }
};