class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for(int row = 0; row < grid.size() - 1; row++)
        {
            for(int col = 0; col < grid[0].size() - 1; col++)
            {
                int b = 0, w = 0;
                if(grid[row][col] == 'B')
                    b++;
                else
                    w++;
                
                if(grid[row][col + 1] == 'B')
                    b++;
                else
                    w++;

                if(grid[row + 1][col] == 'B')
                    b++;
                else
                    w++;

                if(grid[row + 1][col + 1] == 'B')
                    b++;
                else
                    w++;

                if(b >= 3 || w >= 3)
                    return true;
            }
        }
        return false;
    }
};