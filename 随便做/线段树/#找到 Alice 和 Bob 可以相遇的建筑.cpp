#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <deque>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
    {
        int n = heights.size();
        int m = queries.size();
        vector<int> res(m, -1);
        vector<vector<pair<int, int>>> temVec(n);
        for(int i = 0; i < m; i++)
        {
            int a = queries[i][0], b = queries[i][1];
            if(a > b)
                swap(a, b);
            if(a == b || heights[b] > heights[a])
                res[i] = b;
            else
                temVec[b].emplace_back(make_pair(heights[a], i));
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; 
        for(int i = 0; i < n; i++)
        {
            while(!pq.empty() && pq.top().first < heights[i])
            {
                res[pq.top().second] = i;
                pq.pop();
            }
            for(auto &p : temVec[i])
                pq.emplace(p);
        }

        return res;
    }
};

int main()
{
    vector<int> heights = {6, 4, 8, 5, 2, 7};
    vector<vector<int>> queries = {{0, 1}, {0, 3}, {2, 4}, {3, 4}, {2, 2}};

    Solution sol;
    sol.leftmostBuildingQueries(heights, queries);
    return 0;
}