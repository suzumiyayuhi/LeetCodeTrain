#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
/*
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row0;
        vector<int> col0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    row0.emplace_back(i);
                    col0.emplace_back(j);
                }
            }
        }
        for(int k = 0; k < row0.size(); k++)
        {
            int r = row0[k];
            int c = col0[k];
            for(int i = 0; i < m; i++)
                matrix[r][i] = 0;
            for(int i = 0; i < n; i++)
                matrix[i][c] = 0;
        }
    }
*/

    void setZeroes(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();
        bool row0Flag = false;
        bool col0Flag = false;
        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < m; col++)
            {
                if(matrix[row][col] == 0)
                {
                    if(row == 0)
                        row0Flag = true;
                    if(col == 0)
                        col0Flag = true;
                    matrix[0][col] = 0;
                    matrix[row][0] = 0;
                }
            }
        }

        for(int col = 1; col < m; col++)
        {
            if(matrix[0][col] == 0)
            {
                for(int row = 1; row < n; row++)
                {
                    matrix[row][col] = 0;
                }
            }
        }

        for(int row = 1; row < n; row++)
        {
            if(matrix[row][0] == 0)
            {
                for(int col = 1; col < m; col++)
                {
                    matrix[row][col] = 0;
                }
            }
        }

        if(row0Flag)
            for(int col = 0; col < m; col++)
                matrix[0][col] = 0;

        if(col0Flag)
            for(int row = 0; row < n; row++)
                matrix[row][0] = 0;
    }
};

int main()
{
    vector<vector<int>> mm = {{1,1,1},
    {1,0,1},
    {1,1,1}};
    Solution sol;
    sol.setZeroes(mm);

    return 0;
}