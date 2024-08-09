#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Solution
{
public:
    /*
        int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
            vector<int> dic(26, INT_MAX);
            int minSide = INT_MAX;
            for(int i = 0; i < points.size(); i++)
            {
                int tem = max(abs(points[i][0]), abs(points[i][1]));
                if(dic[s[i] - 'a'] >= tem)
                {
                    dic[s[i] - 'a']--;
                    minSide = min(dic[s[i] - 'a'], minSide);
                }
                else
                    dic[s[i] - 'a'] = min(tem, dic[s[i] - 'a']);

            }
            int res = 0;
            for(int i = 0; i < points.size(); i++)
            {
                if(abs(points[i][0]) <= minSide)
                    res++;
            }
            return res;
        }
        */
    int maxPointsInsideSquare(vector<vector<int>> &points, string s)
    {
        vector<int> dic(26, INT_MAX);
        int minSide = INT_MAX - 1;
        int res = 0;
        for (int i = 0; i < points.size(); i++)
        {
            if (dic[s[i] - 'a'] == INT_MAX)
            {
                dic[s[i] - 'a'] = max(abs(points[i][0]), abs(points[i][1]));
            }
            else
            {
                int tem = max(abs(points[i][0]), abs(points[i][1]));
                int temm = max(tem, dic[s[i] - 'a']);
                if (temm - 1 < 0)
                    return res;
                minSide = min(temm - 1, minSide);
                if (tem < dic[s[i] - 'a'])
                    dic[s[i] - 'a'] = tem;
            }
        }

        for (int i = 0; i < 26; i++)
        {
            if (dic[i] <= minSide)
                res++;
        }
        return res;
    }
};

int main()
{
    //string s = "abdca";
    //vector<vector<int>> vv = {{2, 2}, {-1, -2}, {-4, 4}, {-3, 1}, {3, -3}};
    string s = "aaabfc";
    vector<vector<int>> vv = {{16,32}, {27,3}, {23,-14}, {-32,-16}, {-3,26}, {-14,33}};
    //string s = "aa";
    //vector<vector<int>> vv = {{1,-3}, {0,-2}};
    Solution sol;
    sol.maxPointsInsideSquare(vv, s);
    return 0;
}