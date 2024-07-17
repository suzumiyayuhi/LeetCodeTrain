class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int res = 0;
        vector<bool> opened(n, false);
        vector<vector<int>> distance(n, vector<int>(n, 1000000));

        for(int mask = 0; mask < (1 << n); mask++)
        {
            for(int i = 0; i < n; i++)
            {
                opened[i] = mask & (1 << i);
                //mask >> 1;
            }
            fill(distance.begin(), distance.end(), vector<int>(n, 100000));
            for(int i = 0; i < roads.size(); i++)
            {
                int from = roads[i][0];
                int to = roads[i][1];
                int length = roads[i][2];
                if(opened[from] && opened[to])
                {
                    distance[from][to] = min(distance[from][to], length);
                    distance[to][from] = distance[from][to];
                }
            }

            for(int passBy = 0; passBy < n; passBy++)
            {
                if(opened[passBy])
                {
                    for(int from = 0; from < n; from++)
                    {
                        if(opened[from])
                        {
                            for(int to = 0; to < n; to++)
                            {
                                if(opened[to] > 0)
                                {
                                    distance[from][to] = min(distance[from][to], distance[from][passBy] + distance[passBy][to]);
                                    distance[to][from] = distance[from][to];
                                }
                            }
                        }
                    }
                }
            }

            bool flag = false;
            for(int from = 0; from < n; from++)
            {
                if(opened[from])
                {
                    for(int to = from + 1; to < n; to++)
                    {
                        if(opened[to])
                        {
                            if(distance[from][to] > maxDistance)
                            {
                                flag = true;
                                break;
                            }
                        }
                    }
                    if(flag)
                        break;
                }
            }
            if(!flag)
                res++;
        }
        return res;
    }
};