class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> ds;
        for(int i = 0; i < n; i++)
        {
            ds.emplace_back(capacity[i] - rocks[i]);
        }
        sort(ds.begin(), ds.end());
        int res = 0;
        for(int i = 0 ; i < n; i++)
        {
            int temAdd = additionalRocks - ds[i];
            if(temAdd >= 0)
                res++;
            else
                break;
            additionalRocks = temAdd;
        }
        return res;
    }
};