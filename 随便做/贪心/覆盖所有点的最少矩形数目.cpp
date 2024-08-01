class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        sort(points.begin(), points.end());
        int res = 1;
        int start = 0;
        for(int i = 1; i < points.size(); i++)
        {
            if(points[i][0] - points[start][0] > w)
            {
                start = i;
                res++;
            }
        }
        return res;
    }
};