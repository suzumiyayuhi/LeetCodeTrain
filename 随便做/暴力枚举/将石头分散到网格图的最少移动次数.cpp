#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Solution
{
public:
    void process(vector<pair<int, int>> from, vector<pair<int, int>> to, vector<int> cur, int &res, vector<bool> bitSelected)
    {
        if(cur.size() == from.size())
        {
            int temRes = 0;
            for(int i = 0; i < cur.size(); i++)
            {
                int row = from[cur[i]].first, col = from[cur[i]].second;
                temRes += abs(row - to[i].first) + abs(col - to[i].second);
            }

            res = min(temRes, res);
            return;
        }

        vector<int> selected;
        cur.emplace_back(-1);
        for(int i = 0; i < from.size(); i++)
        {
            bool flag = false;
            for(int j = 0; j < selected.size(); j++)
            {
                if (from[selected[j]] == from[i])
                {
                    flag = true;
                    break;
                }
            }
            if(flag)
                continue;
            if(bitSelected[i])
                continue;
            cur[cur.size() - 1] = i;
            selected.emplace_back(i);
            bitSelected[i] = true;
            process(from, to, cur, res, bitSelected);
            bitSelected[i] = false;
        }
    }

    
    int minimumMoves(vector<vector<int>> &grid)
    {
        vector<pair<int, int>> from;
        vector<pair<int, int>> to;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (grid[i][j] > 1)
                {
                    for(int k = 1; k < grid[i][j]; k++)
                        from.emplace_back(make_pair(i, j));
                }
                else if (grid[i][j] == 0)
                    to.emplace_back(make_pair(i, j));
            }
        }

        int res = 9999;
        vector<int> cur;
        vector<bool> bitSelected(from.size(), false);
        process(from, to, cur, res, bitSelected);
        return res;
    }
};

int main()
{
    //vector<vector<int>> ss = {{1,2,2},{1,1,0},{0,1,1}};
    vector<vector<int>> ss = {{3,2,0},{0,1,0},{0,3,0}};
    Solution sol;
    cout << sol.minimumMoves(ss);
    return 0;
}