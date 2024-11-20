class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if(row == 1 || col == 1)
            return 0;
        int res1 = 0, res2 = 0;
        for(int j = 0; j < col; j++)
        {
            for(int i = 0; i < row / 2; i++)
            {
                if(grid[i][j] != grid[row - i -1][j])
                    res1++;
            }
        }

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col / 2; j++)
            {
                if(grid[i][j] != grid[i][col - j - 1])
                    res2++;
            }
        }

        return min(res1, res2);
    }
};