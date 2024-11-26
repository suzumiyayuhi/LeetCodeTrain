class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<vector<int>> graph(n + 1, vector<int>(n + 1, INT_MAX));
        for(int i = 0; i < times.size(); i++)
        {
            int& from = times[i][0];
            int& to = times[i][1];
            int& dis = times[i][2];
            graph[from][to] = dis;
        }

        vector<int> dists(n + 1, INT_MAX);
        dists[0] = 0;
        dists[k] = 0;
        vector<int> done(n + 1, 0);
        while(true)
        {
            int x = -1;
            for(int i = 1; i <= n; i++)
            {
                if(!done[i] && (x < 0 || dists[i] < dists[x]))
                    x = i;
            }
            if(x < 0)
                break;
            if(dists[x] == INT_MAX)
                return -1;
            done[x] = 1;
            for(int y = 1; y <= n; y++)
            {
                if(graph[x][y] == INT_MAX)
                    continue;
                dists[y] = min(dists[y], dists[x] + graph[x][y]);
            }
        }
        return ranges::max(dists);
    }
};