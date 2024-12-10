class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
        int row, col;
        GetStart(board, row, col);
        int res = 0;
        for(int i = 0; i < 4; i++)
        {
            int j = 1;
            while(true)
            {
                int temRow = row + j * dir[i][0];
                int temCol = col + j * dir[i][1];
                if(temRow < 0 || temRow >= board.size())
                    break;
                if(temCol < 0 || temCol >= board.size())
                    break;
                if(board[temRow][temCol] == 'p')
                {
                    res++;
                    break;
                }
                if(board[temRow][temCol] == 'B')
                    break;
                j++;
            }
        }
        return res;
    }

    void GetStart(vector<vector<char>>& board, int& row, int& col)
    {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board.size(); j++)
            {
                if(board[i][j] == 'R')
                {
                    row = i;
                    col = j;
                    return;
                }
            }
        }
    }
};