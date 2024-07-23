class Solution {
public:
    int sumOfPowers(vector<int>& nums, int k) {
        int mm = 1e9 + 7;
        int n = nums.size();
        int res = 0;
        vector<vector<unordered_map<int, int>>> vec(n, vector<unordered_map<int, int>>(k + 1));
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++)
        {
            vec[i][1][INT_MAX] = 1;
            for(int j = 0; j < i; j++)
            {
                int diff = abs(nums[j] - nums[i]);
                for(int p = 2; p <= k; p++)
                {
                    for(auto [v, cnt] : vec[j][p - 1])
                        vec[i][p][min(diff, v)] = (vec[i][p][min(diff, v)] + cnt) % mm;
                }
            }
            
            for(auto [v, cnt] : vec[i][k])
            {
                res = (res + 1ll * v * cnt % mm) % mm;
            }
        }
        return res;
    }
};