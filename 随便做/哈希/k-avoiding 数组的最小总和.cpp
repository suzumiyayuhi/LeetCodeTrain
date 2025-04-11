class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_map<int, int> um;
        int res = 0;
        for(int i = 0, cur = 1; i < n; i++)
        {
            if(cur < k)
                while(um[k - cur] != 0)
                    cur++;
            um[cur]++;
            res += cur;
            cur++;
        }
        return res;
    }
};