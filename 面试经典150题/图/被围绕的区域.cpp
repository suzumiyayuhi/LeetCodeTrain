class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for(int i = 1; i < board.size() - 1; i++)
        {
            for(int j = 1; j < board[0].size() - 1; j++)
            {
                if(board[i][j] == 'X')
                    continue;
                sub(board, i, j);
            }
        }
    }

    void sub(vector<vector<char>>& board, int row, int col)
    {
        int dir[4][2] = {1,0,-1,0,0,1,0,-1};
        stack<pair<int, int>> st;
        stack<pair<int, int>> sst;
        st.push(make_pair(row, col));
        bool flag = true;
        while(!st.empty())
        {
            int r = st.top().first;
            int c = st.top().second;
            st.pop();
            if(r < 0 || r >= board.size())
                continue;
            if(c < 0 || c >= board[0].size())
                continue;
            if(board[r][c] == 'L' || board[r][c] == 'X')
                continue;
            if(r == 0 || r == board.size() - 1)
                flag = false;
            if(c == 0 || c == board[0].size() - 1)
                flag = false;
            board[r][c] = 'L';
            for(int i = 0; i < 4; i++)
                st.push(make_pair(r + dir[i][0], c + dir[i][1]));
            sst.push(make_pair(r, c));
        }

        if(flag)
        {
            while(!sst.empty())
            {
                board[sst.top().first][sst.top().second] = 'X';
                sst.pop();
            }
        }
        else
        {
            while(!sst.empty())
            {
                board[sst.top().first][sst.top().second] = 'O';
                sst.pop();
            }
        }
    }

/*
    bool sub(vector<vector<char>>& board, int row, int col)
    {
        if(row < 0 || row >= board.size())
            return true;
        if(col < 0 || col >= board[0].size())
            return true;

        if(board[row][col] == 'L' || board[row][col] == 'X')
            return true;

        if(board[row][col] == 'O')
        {
            if(row == 0 || row == board.size() - 1)
                return false;
            if(col == 0 || col == board[0].size() - 1)
                return false;
            board[row][col] = 'L';
        }



        bool flag1 = sub(board, row + 1, col);
        bool flag2 = sub(board, row - 1, col);
        bool flag3 = sub(board, row, col + 1);
        bool flag4 = sub(board, row, col - 1);
        if(flag1 && flag2 && flag3 && flag4)
            board[row][col] = 'X';
        else
            board[row][col] = 'O';
        return flag1 && flag2 && flag3 && flag4;
    }
    */
};