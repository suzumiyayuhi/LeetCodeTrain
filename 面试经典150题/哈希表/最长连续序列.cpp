#include <iostream>
#include <unordered_map>
#include <vector>
#include <array>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]] = -1;
        }

        int maxxx = 0;
        
        for(auto sss : mp)
        {
            if(mp.find(sss.first - 1) == mp.end())
            {
                int temmax = 1;
                while(mp.find(sss.first + temmax) != mp.end())
                    temmax++;
                maxxx = max(maxxx, temmax);
            }
        }
        return maxxx;
    }
};


int main()
{
    Solution sol;
    vector<int> ss = {100,4,200,1,3,2};
    sol.longestConsecutive(ss);
    return 0;
}