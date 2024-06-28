class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        int i = 0, j = 0;
        bool flag = true;
        while(i < n)
        {
            int left = intervals[i][0], right = intervals[i][1];
            if(flag && newInterval[0] <= right )
            {
                if(newInterval[1] >= left)
                {
                    left = min(newInterval[0], left);
                    right = max(newInterval[1], right);
                }
                else
                {
                    res.emplace_back(newInterval);
                }
                flag = false;
            }
            while(j + 1 < n && intervals[j + 1][0] <= right)
            {
                right = max(intervals[j + 1][1], right);
                j++;
            }
            res.emplace_back(vector<int>{left, right});
            j++;
            i = j;
        }

        if(flag)
            res.emplace_back(newInterval);
        return res;
    }
};