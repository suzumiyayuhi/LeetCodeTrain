class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        vector<long long> prefix(n + 1, 0);
        long long temMax = 0;
        long long temMin = 0;
        for(int i = 0; i < n; i++)
        {
            prefix[i + 1] = differences[i] + prefix[i];
            temMax = max(temMax, prefix[i + 1]);
            temMin = min(temMin, prefix[i + 1]);
        }

        int res = upper - lower - temMax + temMin;
        if(res < 0)
            return 0;    
        return res + 1;
    }
};