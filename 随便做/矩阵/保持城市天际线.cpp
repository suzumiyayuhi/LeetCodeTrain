class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> rowMax(grid.size(), 0), colMax(grid.size(), 0);
        int res = 0;
        /*
        for(int row = 0; row < grid.size(); row++)
        {
            int temRowMax = grid[row][0];
            for(int col = 1; col < grid[0].size(); col++)
            {
                temRowMax = temRowMax > grid[row][col]? temRowMax : grid[row][col];
            }
            rowMax.emplace_back(temRowMax);
        }

        for(int col = 0; col < grid[0].size(); col++)
        {
            int temColMax = grid[0][col];
            for(int row = 1; row < grid.size(); row++)
            {
                temColMax = temColMax > grid[row][col]? temColMax : grid[row][col];
            }
            colMax.emplace_back(temColMax);
        }
        */
        
        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                rowMax[row] = max(rowMax[row], grid[row][col]);
                colMax[col] = max(colMax[col], grid[row][col]);
            }
        }


        for(int row = 0; row < grid.size(); row++)
        {
            for(int col = 0; col < grid[0].size(); col++)
            {
                res += min(rowMax[row], colMax[col]) - grid[row][col];
            }
        }
        return res;
    }
};