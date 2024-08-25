#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> mp(numCourses, vector<int>());
        vector<int> m(numCourses);
        queue<int> q;
        for(int i = 0; i < prerequisites.size(); i++)
        {
            mp[prerequisites[i][1]].emplace_back(prerequisites[i][0]);
            m[prerequisites[i][0]]++;
        }
            
        for(int i = 0; i < m.size(); i++)
        {
            if(m[i] == 0)
                q.push(i);
        }
        
        vector<int> res;
        while(!q.empty())
        {
            int cur = q.front();
            res.emplace_back(cur);
            q.pop();
            for(int i = 0; i < mp[cur].size(); i++)
            {
                if(--m[mp[cur][i]] == 0)
                    q.push(mp[cur][i]);
            }
        }
        if(res.size() == numCourses)
            return res;
        return vector<int>();
    }
};

int main()
{
    //vector<vector<int>> fd = {{1,0},{2,0},{3,1},{3,2}};
    vector<vector<int>> fd;
    int n = 4;
    Solution sol;
    sol.findOrder(n, fd);
    return 0;
}