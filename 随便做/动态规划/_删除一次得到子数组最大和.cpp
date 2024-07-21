class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int dp1 = arr[0], dp2 = 0, res = dp1;
        for(int i = 1; i < arr.size(); i++)
        {
            dp2 = max(dp1, dp2 + arr[i]);
            dp1 = max(dp1, 0) + arr[i];
            res = max(res, max(dp1, dp2));
        }
        return res;
    }
};