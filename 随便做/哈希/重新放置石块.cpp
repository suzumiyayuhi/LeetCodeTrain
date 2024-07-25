class Solution {
public:
/*
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        for(int i = 0; i < moveFrom.size(); i++)
        {
            if(moveFrom[i] == moveTo[i])
                continue;
            mp[moveTo[i]] += mp[moveFrom[i]];
            mp.erase(moveFrom[i]);
        }
        vector<int> res;
        for(auto x : mp)
            res.emplace_back(x.first);
        return res;
    }
    */
        vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int> se(nums.begin(), nums.end());
        for(int i = 0; i < moveFrom.size(); i++)
        {
            se.erase(moveFrom[i]);
            se.insert(moveTo[i]);
            
        }
        vector<int> res(se.begin(), se.end());

        return res;
    }
};