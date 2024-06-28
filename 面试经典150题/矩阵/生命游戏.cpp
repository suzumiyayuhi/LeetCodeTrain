#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int dir[8][2]={
    1,0,
    0,1,
    -1,0,
    0,-1,
    1,1,
    1,-1,
    -1,1,
    -1,-1};

    void processAlive(vector<vector<int>>& board, const int &row, const int &col)
    {
        int count = 0;
        int rowSize = board.size();
        int colSize = board[0].size();
        for(int i = 0; i < 8; i++)
        {
            int r = row+dir[i][0];  int c = col+dir[i][1];
            if(r < 0 || r >= rowSize || c < 0 || c >= colSize)
                continue;
            if(board[r][c] == 1 || board[r][c] == -1)
                count++;
        }
        if(count == 2 || count == 3)
            board[row][col] = 1;
        else
            board[row][col] = -1;
    }

    void processDead(vector<vector<int>>& board, const int &row, const int &col)
    {
        int count = 0;
        int rowSize = board.size();
        int colSize = board[0].size();
        for(int i = 0; i < 8; i++)
        {
            int r = row+dir[i][0];  int c = col+dir[i][1];
            if(r < 0 || r >= rowSize || c < 0 || c >= colSize)
                continue;
            if(board[r][c] == 1 || board[r][c] == -1)
                count++;
        }
        if(count == 3)
            board[row][col] = -2;
    }

    void gameOfLife(vector<vector<int>>& board) 
    {
        int rowSize = board.size();
        int colSize = board[0].size();
        for(int row = 0; row < rowSize; row++)
        {
            for(int col = 0; col < colSize; col++)
            {
                 if(board[row][col] == 1)
                    processAlive(board, row, col);
                else
                    processDead(board, row, col);
            }
        }

        for(int row = 0; row < rowSize; row++)
        {
            for(int col = 0; col < colSize; col++)
            {
                 if(board[row][col] == -1)
                    board[row][col] = 0;
                else if(board[row][col] == -2)
                    board[row][col] = 1;
            }
        }
    }
};


int main()
{
    Solution sol;
    vector<vector<int>> dd = {{0,1,0},
    {0,0,1},
    {1,1,1},
    {0,0,0}};
    for(int i = 0; i < dd.size(); i++)
    {
        for(int j = 0; j < dd[0].size(); j++)
        {
            cout<<dd[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    sol.gameOfLife(dd);
    
    for(int i = 0; i < dd.size(); i++)
    {
        for(int j = 0; j < dd[0].size(); j++)
        {
            cout<<dd[i][j]<<" ";
        }
        cout<<endl;
    }
}