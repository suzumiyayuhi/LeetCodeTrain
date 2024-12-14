class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int MOD = 1e9 + 7;
        vector<int> res = nums;
        if(multiplier == 1)
            return res;
        
        vector<pair<long long, int>> h;
        for(int i = 0; i < res.size(); i++)
        {
            h.emplace_back(make_pair(nums[i], i));
        }
        make_heap(h.begin(), h.end(), greater<>());
        
        while(k)
        {
            pop_heap(h.begin(), h.end(), greater<>());
            h.back().first *= multiplier;
            push_heap(h.begin(), h.end(), greater<>());
            k--;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            res[h[i].second] = h[i].first % MOD;
        }
        return res;
    }
};