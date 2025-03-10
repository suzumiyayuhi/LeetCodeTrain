class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int max1 = arrays[0].back(), min1 = arrays[0][0];
        int res = INT_MIN;
        for(int i = 1; i < arrays.size(); i++)
        {
            res = max(res, max1 - arrays[i][0]);
            res = max(res, arrays[i].back() - min1);
            max1 = max(max1, arrays[i].back());
            min1 = min(min1, arrays[i][0]);
        }
        return res;
    }
};