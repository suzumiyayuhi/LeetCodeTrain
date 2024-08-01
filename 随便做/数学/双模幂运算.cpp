#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    /*
        vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
            vector<int> res;

            for(int i = 0; i < variables.size(); i++)
            {
                int a = variables[i][0];
                int b = variables[i][1];
                int c = variables[i][2];
                int m = variables[i][3];

                int temSum = a;
                while(--b > 0)
                {
                    temSum *= a;
                    temSum %= 10;
                }
                int sum = temSum;
                while(--c > 0)
                {
                    sum *= temSum;
                    sum %= m;
                }


                if(sum == target)
                    res.emplace_back(i);
            }
            return res;
        }
        */
    int fastPow(int a, int b, int m)
    {
        int res = 1;
        while(b)
        {
            if(b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>=1;
        }
        return res;
    }
    vector<int> getGoodIndices(vector<vector<int>> &variables, int target)
    {
        vector<int> res;
            for(int i = 0; i < variables.size(); i++)
            {
                int a = variables[i][0];
                int b = variables[i][1];
                int c = variables[i][2];
                int m = variables[i][3];

                int temSum = fastPow(a, b, 10);
                int sum = fastPow(temSum, c, m);

                if(sum == target)
                    res.emplace_back(i);
            }
            return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> d = {{2, 3, 3, 10}, {3, 3, 3, 1}, {6, 1, 1, 4}};
    vector<int> fg = sol.getGoodIndices(d, 2);
    for (int i = 0; i < fg.size(); i++)
        cout << fg[i] << " ";
    return 0;
}