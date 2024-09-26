#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class Solution
{
public:
    /*
        long long distinctNames(vector<string> &ideas)
        {
            int n = ideas.size();
            unordered_map<string, int> um;
            for (int i = 0; i < n; i++)
            {
                um[ideas[i]] = 1;
            }
            long long res = 0;
            for (int i = 0; i < n - 1; i++)
            {
                string &a = ideas[i];
                for (int j = i + 1; j < n; j++)
                {
                    string &b = ideas[j];
                    if (a[0] == b[0])
                        continue;

                    if (um.find(b[0] + a.substr(1, a.size() - 1)) != um.end() || um.find(a[0] + b.substr(1, b.size() - 1)) != um.end())
                        continue;
                    res++;
                }
            }
            res *= 2;
            return res;
        }
        */
    /*
 long long distinctNames(vector<string> &ideas)
 {
     int n = ideas.size();
     unordered_map<string, vector<int>> um;
     for (int i = 0; i < n; i++)
     {
         if(um.find(ideas[i].substr(1, ideas[i].size() - 1)) != um.end())
             um[ideas[i].substr(1, ideas[i].size() - 1)][ideas[i][0] - 'a'] = 1;
         else
         {
             um[ideas[i].substr(1, ideas[i].size() - 1)] = vector<int>(26, 0);
             um[ideas[i].substr(1, ideas[i].size() - 1)][ideas[i][0] - 'a'] = 1;
         }
     }
     long long res = 0;
     for (int i = 0; i < n - 1; i++)
     {
         string &a = ideas[i];
         for (int j = i + 1; j < n; j++)
         {
             string &b = ideas[j];
             if (a[0] == b[0])
                 continue;

             if (um[a.substr(1, a.size() - 1)][b[0] - 'a'] || um[b.substr(1, b.size() - 1)][a[0] - 'a'])
                 continue;
             res++;
         }
     }
     res *= 2;
     return res;
 }
 */
    long long distinctNames(vector<string> &ideas)
    {
        int n = ideas.size();
        vector<int> heads(26, 0);
        vector<vector<int>> intersection(26, vector<int>(26, 0));
        unordered_map<string, vector<int>> um;
        for (int i = 0; i < n; i++)
        {
            int head = ideas[i][0] - 'a';
            heads[head]++;
            if (um.find(ideas[i].substr(1)) != um.end())
            {
                um[ideas[i].substr(1)][head] = 1;
            }
            else
            {
                um[ideas[i].substr(1)] = vector(26, 0);
                um[ideas[i].substr(1)][head] = 1;
            }
            for (int j = 0; j < 26; j++)
            {
                if (um[ideas[i].substr(1)][j] == 1)
                {
                    intersection[head][j]++;
                    intersection[j][head]++;
                }
            }
        }
        long long res = 0;
        for (int i = 0; i < 25; i++)
        {
            for (int j = i + 1; j < 26; j++)
            {
                res += (long long)(heads[i] - intersection[i][j]) * (heads[j] - intersection[i][j]);
            }
        }
        res *= 2;
        return res;
    }
    /*
        long long distinctNames(vector<string> &ideas)
        {
            int n = ideas.size();
            vector<int> heads(26, 0);
            vector<vector<int>> intersection(26, vector<int>(26, 0));
            unordered_map<string, int> um;
            for (int i = 0; i < n; i++)
            {
                int head = ideas[i][0] - 'a';
                heads[head]++;
                um[ideas[i].substr(1)] = um[ideas[i].substr(1)] | (1 << head);
                for(int j = 0; j < 26; j++)
                {
                    if((um[ideas[i].substr(1)] >> j) & 1)
                    {
                        intersection[head][j]++;
                        intersection[j][head]++;
                    }
                }
            }
            long long res = 0;
            for(int i = 0; i < 25; i++)
            {
                for(int j = i + 1; j < 26; j++)
                {
                    res += (long long)(heads[i] - intersection[i][j]) * (heads[j] - intersection[i][j]);
                }
            }
            res *= 2;
            return res;
        }
        */
};

int main()
{
    vector<string> vecs = {"coffee", "donuts", "time", "toffee"};
    Solution sol;
    sol.distinctNames(vecs);
    return 0;
}

