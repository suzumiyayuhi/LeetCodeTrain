#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        const int MARK = 999;
        vector<int> res;
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        int dir[4][2] = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}};
        int dirRow = 0;
        int row = 0, col = 0;
        
        
        while (matrix[row][col] != MARK)
        {
            res.emplace_back(matrix[row][col]);
            matrix[row][col] = MARK;
            int temRow = row + dir[dirRow][0]; int temCol = col + dir[dirRow][1];
            if (temRow < 0 || temRow >= rowSize || temCol < 0 || temCol >= colSize ||
                matrix[temRow][temCol] == MARK)
            {
                dirRow++;
                dirRow %= 4;
                temRow = row + dir[dirRow][0];
                temCol = col + dir[dirRow][1];
            }
            row = temRow;
            col = temCol;
            if (row < 0 || row >= rowSize || col < 0 || col >= colSize ||
                matrix[row][col] == MARK)
                break;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> board = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    auto tem = sol.spiralOrder(board);
    for (int i = 0; i < tem.size(); i++)
    {
        cout << tem[i] << " ";
    }
    return 0;
}