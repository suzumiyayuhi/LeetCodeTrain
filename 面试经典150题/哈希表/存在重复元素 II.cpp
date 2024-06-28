class Solution {
public:
/*
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            auto sss = mp.find(nums[i]);
            if(sss != mp.end())
            {
                int m = sss->second.size();
                for(int j = 0; j < m; j++)
                {
                    if(i - sss->second[j] <= k)
                        return true;
                }
            }
            
            mp[nums[i]].emplace_back(i);
        }
        return false;
    }
*/
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            auto sss = mp.find(nums[i]);
            if(sss != mp.end())
            {
                if(i - sss->second <= k)
                    return true;
                else
                    sss->second = i;
            }
            else
                mp[nums[i]] = i;
            
        }
        return false;
    }
};