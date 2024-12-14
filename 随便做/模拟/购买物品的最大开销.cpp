class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) 
    {
        int n = values.size();
        int m = values[0].size();
        vector<int> ll;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                ll.emplace_back(values[i][j]);
            }
        }
        sort(ll.begin(), ll.end());
        long long res = 0;
        for(int i = 0; i < ll.size(); i++)
        {
            res = res + (i + 1) * (long long)ll[i];
        }
        return res;
    }
};