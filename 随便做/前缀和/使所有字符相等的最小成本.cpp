class Solution {
public:
    long long minimumCost(string s) {
        int n = s.size();
        vector<vector<long long>> suffix(n + 1, vector<long long>(2, 0));
        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] == '0')
            {
                suffix[i][0] = suffix[i + 1][0];
                suffix[i][1] = suffix[i + 1][0] + n - i;
            }
            else
            {
                suffix[i][0] = suffix[i + 1][1] + n - i;
                suffix[i][1] = suffix[i + 1][1];
            }
        }
        
        vector<long long> pre(2, 0);
        long long res = 1e18;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
            {
                pre[1] = pre[0] + i + 1;
            }
            else
            {
                pre[0] = pre[1] + i + 1;
            }
            res = min(res, min(pre[0] + suffix[i + 1][0], pre[1] + suffix[i + 1][1]));
        }
        return res;
    }
};