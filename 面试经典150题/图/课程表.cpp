#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> um(numCourses, vector<int>());
        vector<int> indeg(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int &from = prerequisites[i][1];
            int &to = prerequisites[i][0];
            um[from].emplace_back(to);
            indeg[to]++;
        }

        queue<int> q;
        for (int tem = 0; tem < um.size(); tem++)
        {
            if (indeg[tem] == 0)
                q.push(tem);
        }

        int count = 0;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            count++;
            for (int i = 0; i < um[cur].size(); i++)
            {
                indeg[um[cur][i]]--;
                if (indeg[um[cur][i]] == 0)
                    q.push(um[cur][i]);
            }
        }

        return count == numCourses;
    }

    /*
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> um(numCourses + 1, vector<int>());
        vector<int> indeg(numCourses + 1, 0);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int &from = prerequisites[i][1];
            int &to = prerequisites[i][0];
            um[from].emplace_back(to);
            indeg[to]++;
        }

        for (int tem = 0; tem < um.size(); tem++)
        {
            if (um[tem].empty())
                continue;

            vector<int> record(numCourses + 1, 0);
            queue<int> q;
            q.push(tem);
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();

                for (int i = 0; i < um[cur].size(); i++)
                {
                    int &next = um[cur][i];
                    if (record[next] == 0)
                        q.push(next);
                    record[next]++;
                    if (record[next] > indeg[next])
                        return false;

                }
            }
        }

        return true;
    }
    */
};

int main()
{
    int numCourses = 4;
    // vector<vector<int>> prerequisites = {{1, 3}, {3, 1}, {3, 2}, {1, 0}, {2, 0}};
    // vector<vector<int>> prerequisites = {{1, 3}, {3, 1}, {1, 0}, {3, 2}};
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    Solution sol;
    sol.canFinish(numCourses, prerequisites);
    return 0;
}