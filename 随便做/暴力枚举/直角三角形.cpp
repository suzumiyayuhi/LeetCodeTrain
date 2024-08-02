class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int rowSize = grid.size();
        int colSize = grid[0].size();
        int rowxx[1000] = {0};
        int colxx[1000] = {0};
        long long res = 0;
        for(int row = 0; row < rowSize; row++)
        {
            for(int col = 0; col < colSize; col++)
            {
                if(grid[row][col] == 1)
                {
                    rowxx[row]++;
                    colxx[col]++;
                }
            }
        }

        for(int row = 0; row < rowSize; row++)
        {
            for(int col = 0; col < colSize; col++)
            {
                if(grid[row][col] == 1)
                {
                    long long tem = (rowxx[row] - 1) * (colxx[col] - 1);
                    res += tem;
                }
            }
        }
        return res;
    }
};