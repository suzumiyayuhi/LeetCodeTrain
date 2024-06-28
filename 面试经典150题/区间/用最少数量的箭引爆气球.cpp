#include <iostream>
#include <unordered_map>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        vector<vector<int>> res;
        int i = 0, j = 0;
        while(i < n)
        {
            int left = points[i][0], right = points[i][1];
            while(j + 1 < n && points[j + 1][0] <= right)
            {
                right = min(points[j + 1][1], right);
                j++;
            }
            res.emplace_back(vector<int>{left, right});
            j++;
            i = j;
        }
        return res.size();
    }
};


int main()
{
    Solution sol;
    vector<vector<int>> ss = {{10,16},{2,8},{1,6},{7,12}};
    cout << sol.findMinArrowShots(ss);
    return 0;
}