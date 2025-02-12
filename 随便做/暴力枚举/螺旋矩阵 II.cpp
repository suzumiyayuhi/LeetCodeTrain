class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int cur = 1;
        int up = 0, down = n - 1, left = 0, right = n - 1;
        while(up < down || left < right)
        {
            for(int i = left; i <= right; i++)
            {
                res[up][i] = cur;
                cur++;
            }
            up++;
            for(int i = up; i <= down; i++)
            {
                res[i][right] = cur;
                cur++;
            }
            right--;
            for(int i = right; i >= left; i--)
            {
                res[down][i] = cur;
                cur++;
            }
            down--;
            for(int i = down; i >= up; i--)
            {
                res[i][left] = cur;
                cur++;
            }
            left++;
        }
        if(n % 2)
            res[n / 2][n / 2] = cur;
        return res;
    }
};