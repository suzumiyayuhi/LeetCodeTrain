class Solution {
public:
    int totalNQueens(int n) 
    {
        int res = 0;
        vector<vector<int>> board(n, vector<int>(n, 0));

        sub(board, 0, res);

        return res;
    }

    void sub(vector<vector<int>> &board, int cur, int &res)
    {
        if(cur == board.size())
        {
            res++;
            return;
        }
        for(int i = 0; i < board.size(); i++)
        {
            if(check(board, cur, i))
            {
                board[cur][i] = 1;
                sub(board, cur + 1, res);
                board[cur][i] = 0;
            }
        }
    }

    bool check(vector<vector<int>> &board, int row, int col)
    {
        for(int i = 0; i < board.size(); i++)
        {
            if(board[row][i])
                return false;
        }
        for(int i = 0; i < board.size(); i++)
        {
            if(board[i][col])
                return false;
        }

        for(int i = 0; ; i++)
        {
            if(row + i >= board.size() ||  col + i >= board.size())
                break;
            if(board[row + i][col + i])
                return false;
        }
        for(int i = 0; ; i++)
        {
            if(row + i >= board.size() ||  col - i < 0)
                break;
            if(board[row + i][col - i])
                return false;
        }
        for(int i = 0; ; i++)
        {
            if(row - i < 0 ||  col + i >= board.size())
                break;
            if(board[row - i][col + i])
                return false;
        }
        for(int i = 0; ; i++)
        {
            if(row - i < 0 || col - i < 0)
                break;
            if(board[row - i][col - i])
                return false;
        }

        return true;
    }
};
