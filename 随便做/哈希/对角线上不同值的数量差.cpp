class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                ans[i][j] = abs(checkBottomRight(i, j, grid) - checkTopLeft(i, j, grid));
            }
        }

        return ans;
    }

    int checkTopLeft(int row, int col, vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size();
        //unordered_map<int,int> um;
        set<int> ss;
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            ss.insert(grid[i][j]);
        }
        return ss.size();
    }

    int checkBottomRight(int row, int col, vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size();
        //unordered_map<int,int> um;
        set<int> ss;
        for(int i = row + 1, j = col + 1; i < n && j < m; i++, j++)
        {
            ss.insert(grid[i][j]);
        }
        return ss.size();
    }
};