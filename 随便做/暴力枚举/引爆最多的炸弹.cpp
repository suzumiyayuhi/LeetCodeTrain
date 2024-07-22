#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    /*
        int maximumDetonation(vector<vector<int>> &bombs)
        {
            int res = 0;
            for (int i = 0; i < bombs.size(); i++)
            {
                stack<vector<int>> st;
                vector<bool> selected(bombs.size(), false);
                st.push(bombs[i]);
                selected[i] = true;
                int temRes = 1;
                while (!st.empty())
                {
                    long long x1 = st.top()[0];
                    long long y1 = st.top()[1];
                    long long r = st.top()[2];
                    st.pop();
                    for (int j = 0; j < bombs.size(); j++)
                    {
                        if (selected[j])
                            continue;
                        long long x2 = bombs[j][0];
                        long long y2 = bombs[j][1];
                        if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= r * r)
                        {
                            selected[j] = true;
                            st.push(bombs[j]);
                            temRes++;
                        }
                    }
                }
                res = max(res, temRes);
            }
            return res;
        }
    */

    /*
        int maximumDetonation(vector<vector<int>> &bombs)
        {
            int n = bombs.size();
            unordered_map<int, vector<int>> bombMap;
            for(int i = 0; i < n; i++)
            {
                long long x1 = bombs[i][0];
                long long y1 = bombs[i][1];
                long long r = bombs[i][2];
                for(int j = 0; j < n; j++)
                {
                    long long x2 = bombs[j][0];
                    long long y2 = bombs[j][1];
                    if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= r * r)
                    {
                        bombMap[i].emplace_back(j);
                    }
                }
            }


            int res = 0;
            for (int i = 0; i < n; i++)
            {
                stack<int> st;
                vector<bool> selected(n, false);
                st.push(i);
                selected[i] = true;
                int temRes = 1;
                while (!st.empty())
                {
                    int index = st.top();
                    st.pop();
                    for(int j = 0; j < bombMap[index].size(); j++)
                    {
                        if(selected[bombMap[index][j]])
                            continue;
                        temRes++;
                        selected[bombMap[index][j]] = true;
                        st.push(bombMap[index][j]);
                    }
                }
                res = max(res, temRes);
            }
            return res;
        }
        */

    int maximumDetonation(vector<vector<int>> &bombs)
    {
        int n = bombs.size();
        unordered_map<int, vector<int>> bombMap;
        
        for (int i = 0; i < n; i++)
        {
            long long r = bombs[i][2];
            for (int j = 0; j < n; j++)
            {
                long long dx = bombs[i][0] - bombs[j][0];
                long long dy = bombs[i][1] - bombs[j][1];
                if (dx * dx + dy * dy <= r * r)
                {
                    bombMap[i].emplace_back(j);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            queue<int> q;
            vector<int> selected(n);
            q.push(i);
            selected[i] = true;
            int temRes = 1;
            while (!q.empty())
            {
                int index = q.front();
                q.pop();
                for (const int nidx : bombMap[index])
                {
                    if (selected[nidx])
                        continue;
                    temRes++;
                    q.push(nidx);
                    selected[nidx] = true;
                }
            }
            res = max(res, temRes);
        }
        return res;
    }
};