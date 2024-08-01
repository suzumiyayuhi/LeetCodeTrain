class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        vector<int> ans;
        vector<int> region;
        region.emplace_back(positions[0][1]);
        ans.emplace_back(positions[0][1]);
        for(int i = 1; i < n; i++)
        {
            int left = positions[i][0];
            int right = positions[i][0] + positions[i][1];
            int height = positions[i][1];
            int res = height;
            for(int j = 0; j < region.size(); j++)
            {
                int temLeft = positions[j][0];
                int temRight = positions[j][0] + positions[j][1];
                int temHeight = region[j];
                if(left >= temLeft && left < temRight || right > temLeft && right <= temRight ||
                    left <= temLeft && right >= temRight)
                {
                    res = max(res, height + temHeight);
                }
            }
            ans.emplace_back(max(ans[i - 1], res));
            region.emplace_back(res);
        }
        return ans;
    }
};