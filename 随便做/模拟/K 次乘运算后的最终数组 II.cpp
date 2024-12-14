class Solution {
public:
    long long MOD = 1e9 + 7;

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<int> res = nums;
        if(multiplier == 1)
            return res;
        
        vector<pair<long long, int>> h;
        for(int i = 0; i < res.size(); i++)
        {
            h.emplace_back(make_pair(nums[i], i));
        }
        make_heap(h.begin(), h.end(), greater<>());
        
        int temMax = ranges::max(nums);
        while(k && h[0].first < temMax)
        {
            pop_heap(h.begin(), h.end(), greater<>());
            h.back().first *= multiplier;
            push_heap(h.begin(), h.end(), greater<>());
            k--;
        }

        sort(h.begin(), h.end());
        int t = k / nums.size();
        for(int i = 0; i < nums.size(); i++)
        {
            
            if(k % nums.size())
            {
                k--;
                res[h[i].second] = (h[i].first % MOD) * quickPow(multiplier, t + 1) % MOD;
            }
            else
                res[h[i].second] = (h[i].first % MOD) * quickPow(multiplier, t) % MOD;
        }
        return res;
    }

    long long quickPow(long long m, long long t)
    {
        long long res = 1;
        while(t)
        {
            if(t & 1)
                res = (res * m) % MOD;
            t >>= 1;
            m = (m * m) %  MOD;
        }
        return res;
    }
};