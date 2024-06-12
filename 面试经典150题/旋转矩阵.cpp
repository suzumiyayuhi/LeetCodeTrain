#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        int oriRight = colSize - 1;
        int left = 0, right = colSize - 1, top = 0, bottom = rowSize - 1;
        while (left < right && top < bottom)
        {
            for (int col = right; col >= left; col--)
            {
                swap(matrix[top][col], matrix[oriRight - col][top]);
            }
            top++;

            for (int row = top; row <= bottom; row++)
            {
                swap(matrix[row][left], matrix[oriRight - left][row]);
            }
            left++;

            for (int col = left; col < right; col++)
            {
                swap(matrix[bottom][col], matrix[oriRight - col][bottom]);
            }
            bottom--;

            right--;

        }
    }
};
