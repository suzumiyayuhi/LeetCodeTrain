class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        sub(candidates, target, cur, res, 0);
        return res;
    }

    void sub(vector<int>& candidates, int &target, vector<int> &cur, vector<vector<int>> &res, int idx)
    {
        if(target < 0 || idx == candidates.size())
            return;
        if(target == 0)
        {
            res.emplace_back(cur);
            return;
        }
        sub(candidates, target, cur, res, idx + 1);

        if(target > 0)
        {
            cur.emplace_back(candidates[idx]);
            target -= candidates[idx];
            sub(candidates, target, cur, res, idx);
            target += candidates[idx];
            cur.erase(cur.end());
        }
    }
};