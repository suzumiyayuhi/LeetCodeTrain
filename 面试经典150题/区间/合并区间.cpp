class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int i = 0, j = 0;
        while(i < n)
        {
            int left = intervals[i][0], right = intervals[i][1];
            while(j + 1 < n && intervals[j + 1][0] <= right)
            {
                right = max(intervals[j + 1][1], right);
                j++;
            }
            res.emplace_back(vector<int>{left, right});
            j++;
            i = j;
        }
        return res;
    }
};