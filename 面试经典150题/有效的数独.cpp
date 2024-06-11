#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        for (int row = 0; row < board.size(); row++)
        {
            for (int col = 0; col < board[row].size(); col++)
            {
                if(board[row][col] == '.')
                    continue;
                for(int temCol = 0; temCol < board[row].size(); temCol++)
                {
                    if(temCol == col)
                        continue;
                    if(board[row][temCol] == board[row][col])
                        return false;
                }
                for(int temRow = 0; temRow < board.size(); temRow++)
                {
                    if(temRow == row)
                        continue;
                    if(board[temRow][col] == board[row][col])
                        return false;
                }
                
                short lowTemRow = row / 3 * 3;  short lowTemCol = col / 3 * 3;
                short upTemRow = (row / 3 + 1) * 3;  short upTemCol = (col / 3 + 1) * 3;
                for(int temRow = lowTemRow; temRow < upTemRow; temRow++)
                {
                    for(int temCol = lowTemCol; temCol < upTemCol; temCol++)
                    {
                        if(temRow == row && temCol == col)
                            continue;
                        if(board[temRow][temCol] == board[row][col])
                            return false;
                    }
                }

            }
        }
        return true;
    }
    
};

int main()
{
    Solution sol;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    if (sol.isValidSudoku(board))
        cout << "gggg" << endl;

    return 0;
}