#include <iostream>
#include <unordered_map>
#include <vector>
#include <array>
using namespace std;

class Solution
{
public:
/*
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]].emplace_back(i);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int temN = target - nums[i];
            auto rr = mp.find(temN);
            if (rr != mp.end())
            {
                if (rr->second[0] == i)
                {
                    if(rr->second.size() == 1)
                    {
                        continue;
                    }
                    else
                        return vector<int>{i, rr->second[1]};
                }
                else
                    return vector<int>{i, rr->second[0]};
                    
            }
        }
        return vector<int>{};
    }
    */
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            int ss = target - nums[i];
            auto aaa = mp.find(ss);
            if(aaa != mp.end())
            {
                return vector<int>{i, aaa->second};
            }
            mp[nums[i]] = i;
        }
        return vector<int>{};
    }
};

int main()
{
    Solution sol;
    vector<int> strs = {2, 7, 11, 15};
    auto dd = sol.twoSum(strs, 9);
    return 0;
}