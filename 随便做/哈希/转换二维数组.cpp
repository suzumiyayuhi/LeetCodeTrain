class Solution {
public:
/*
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int, int> um;
        for(int i = 0; i < nums.size(); i++)
        {
            um[nums[i]]++;
        }
        int count = 0;
        while(count != nums.size())
        {
            vector<int> temVec;
            for(auto t : um)
            {
                if(t.second != 0)
                {
                    temVec.emplace_back(t.first);
                    um[t.first]--;
                    count++;
                }
            }
            if(!temVec.empty())
                res.emplace_back(temVec);
        }

        return res;
    }
    */
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int, int> um;
        for(int i = 0; i < nums.size(); i++)
        {
            um[nums[i]]++;
        }

        while(!um.empty())
        {
            vector<int> temVec;
            for(auto it = um.begin(); it != um.end();)
            {
                if(it->second == 0)
                {
                    it = um.erase(it);
                }
                else
                {
                    temVec.emplace_back(it->first);
                    it->second--;
                    it++;
                }
            }
            if(!temVec.empty())
                res.emplace_back(temVec);
        }

        return res;
    }
};