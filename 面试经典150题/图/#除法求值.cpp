#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> mp;
        int index = 0;
        for(int i = 0; i < equations.size(); i++)
        {
            if(mp.find(equations[i][0]) == mp.end())
                equations[i][0] = index++;
            if(mp.find(equations[i][1]) == mp.end())
                equations[i][1] = index++;
        }

        //unordered_map<int, vector<pair<int, double>>> edges;
        vector<vector<pair<int, double>>> edges(index);
        for(int i = 0; i < equations.size(); i++)
        {
            int from = mp[equations[i][0]];
            int to = mp[equations[i][1]];
            edges[from].emplace_back(make_pair(to, values[i]));
            edges[to].emplace_back(make_pair(from, 1.0 / values[i]));
        }

        vector<double> res;
        for(int i = 0; i < queries.size(); i++)
        {
            double temRes = -1.0;
            if(mp.find(queries[i][0]) != mp.end() && mp.find(queries[i][1]) != mp.end())
            {
                int from = mp[queries[i][0]];
                int to = mp[queries[i][1]];
                if(from == to)
                    temRes = 1.0;
                else
                {
                    queue<int> points;
                    points.push(from);
                    vector<double> ratios(index, -1.0);
                    ratios[from] = 1.0;
                    
                    while(!points.empty() && ratios[to] < 0)
                    {
                        int tem = points.front();
                        points.pop();

                        vector<pair<int, double>> temVec = edges[tem];
                        for(int j = 0; j < temVec.size(); j++)
                        {
                            if(ratios[temVec[j].first] < 0)
                            {
                                ratios[temVec[j].first] = ratios[tem] * temVec[j].second;
                                points.push(temVec[j].first);
                            }
                        }
                    }
                    temRes = ratios[to];
                }
                
            }
            res.emplace_back(temRes);
        }

        return res;
    }
};

int main()
{
    vector<vector<string>> equations = {{"a","b"},{"b","c"}};
    vector<double> values = {2, 0, 3, 0};
    vector<vector<string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    Solution sol;
    sol.calcEquation(equations, values, queries);
    return 0;

}