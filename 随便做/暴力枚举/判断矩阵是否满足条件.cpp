class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        for(int row = 0; row < grid.size(); row++)
        {
            for(int col = 0; col < grid[0].size(); col++)
            {
                if(row + 1 < grid.size())
                    if(grid[row][col] != grid[row + 1][col])
                        return false;
                if(col + 1 < grid[0].size())
                    if(grid[row][col] == grid[row][col + 1])
                        return false;
            }
        }
        return true;
    }
};