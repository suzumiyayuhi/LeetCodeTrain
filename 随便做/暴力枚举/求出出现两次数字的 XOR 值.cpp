class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        vector<int> ccc;
        vector<int> tb(60, 0);
        for(int i = 0; i < nums.size(); i++)
        {
            if(tb[nums[i]])
                ccc.emplace_back(nums[i]);
            tb[nums[i]]++;
        }
        if(ccc.empty())
            return 0;
        int res = ccc[0];
        for(int i = 1; i < ccc.size(); i++)
        {
            res ^= ccc[i];
        }
        return res;
    }
};