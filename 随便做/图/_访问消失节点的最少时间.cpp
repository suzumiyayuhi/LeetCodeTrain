class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, vector<int> &disappear)
    {
        vector<vector<pair<int, int>>> distance(n, vector<pair<int, int>>());
        for (int i = 0; i < edges.size(); i++)
        {

            int from = edges[i][0];
            int to = edges[i][1];
            int length = edges[i][2];
            distance[from].emplace_back(to ,length);
            distance[to].emplace_back(from, length);
        }

        vector<int> res(n, -1);
        if (n > 0)
            res[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, 0);
        while(!pq.empty())
        {
            int time = pq.top().first;
            int passed = pq.top().second;
            pq.pop();
            if(time > res[passed])
                continue;
            
            for(int i = 0; i < distance[passed].size(); i++)
            {
                int len = distance[passed][i].second + time;
                int to = distance[passed][i].first;
                if(len < disappear[to] && (res[to] == -1 || res[to] > len))
                {
                    res[to] = len;
                    pq.emplace(len, to);
                }
            }
        }
        return res;
    }
};