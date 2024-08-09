class Solution
{
public:
    int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

    int numIslands(vector<vector<char>> &grid)
    {
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '0' || grid[i][j] == '3')
                    continue;
                sub(grid, i, j);
                res++;
            }
        }
        return res;
    }

    void sub(vector<vector<char>> &grid, int i, int j)
    {
        stack<pair<int, int>> st;
        st.push(make_pair(i, j));
        while (!st.empty())
        {
            int temR = st.top().first;
            int temC = st.top().second;
            st.pop();
            if (temR < 0 || temR >= grid.size())
                continue;
            if (temC < 0 || temC >= grid[0].size())
                continue;
            if (grid[temR][temC] == '0' || grid[temR][temC] == '3')
                continue;
            grid[temR][temC] = '3';
            for (int i = 0; i < 4; i++)
                st.push(make_pair(temR + dir[i][0], temC + dir[i][1]));
        }
    }
};