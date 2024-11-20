class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        if(row == 1 && col == 1)
            return grid[0][0] == 1;
        int res = 0;
        for(int i = 0; i < row / 2; i++)
        {
            for(int j = 0; j < col / 2; j++)
            {
                int count[2] = {0};
                grid[i][j] == 0 ? count[0]++ : count[1]++;
                grid[i][col - j - 1] == 0 ? count[0]++ : count[1]++;
                grid[row - i - 1][j] == 0 ? count[0]++ : count[1]++;
                grid[row - i - 1][col - j -1] == 0 ? count[0]++ : count[1]++;
                res += min(count[0], count[1]);
            }
        }

        int count1 = 0;
        int reverse = 0;
        if(row % 2)
        {
            for(int j = 0; j < col / 2; j++)
            {
                if(grid[row / 2][j] != grid[row / 2][col - j - 1])
                {
                    reverse++;
                    count1++;
                }
                else
                {
                    grid[row / 2][j] == 1 ? count1 += 2 : count1;
                }
                
            }
            
        }
        if(col % 2)
        {
            for(int i = 0; i < row / 2; i++)
            {
                if(grid[i][col / 2] != grid[row - i - 1][col / 2])
                {
                    reverse++;
                    count1++;
                }
                else
                {
                    grid[i][col / 2] == 1 ? count1 += 2 : count1;
                }
            }
        }
        if(row % 2 && col % 2 )
        {
            if(grid[row / 2][col / 2])
                res++; 
        }
        res += reverse;
        if(reverse < 4 && (count1 + reverse) % 4 && (count1 - reverse) % 4 && count1 % 4)
        {
            res += min((count1 + reverse) % 4, 4 - (count1 + reverse) % 4);
        }
        return res;
    }
};