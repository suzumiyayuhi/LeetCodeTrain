class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> res;
        vector<vector<int>> tb(n, vector<int>());
        for(int i = 0; i < n - 1; i++)
        {
            tb[i].emplace_back(i + 1);
        }

        for(int i = 0; i < queries.size(); i++)
        {
            vector<int> passed(n, 0);
            tb[queries[i][0]].emplace_back(queries[i][1]);
            queue<pair<int, int>> q;
            q.push(make_pair(0,0));
            
            while(!q.empty())
            {
                int node = q.front().first;
                int count = q.front().second;
                if(node == n - 1)
                {
                    res.emplace_back(count);
                    break;
                }
                q.pop();
                for(int j = 0; j < tb[node].size(); j++)
                {
                    if(passed[tb[node][j]])
                        continue;
                    passed[tb[node][j]] = 1;
                    q.push(make_pair(tb[node][j], count + 1));
                
                }
            }
        }

        return res;
    }
};