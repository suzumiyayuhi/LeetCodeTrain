#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int checkRecord(int n) {
        int md = 1e9 + 7;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        dp[1][0][0] = 1;
        dp[1][0][1] = 1;
        dp[1][0][2] = 0;
        dp[1][1][0] = 1;
        dp[1][1][1] = 0;
        dp[1][1][2] = 0;

        for(int i = 2; i <= n; i++)
        {
            //P
            for(int j = 0; j < 2; j++)
                for(int k = 0; k < 3; k++)
                    dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][k]) % md;

            //A
            for(int j = 0; j < 3; j++)
                dp[i][1][0] = (dp[i][1][0] + dp[i - 1][0][j]) % md;

            //L
            for(int j = 0; j < 2; j++)
                for(int k = 1; k < 3; k++)
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % md; 

        }
        int sum = 0;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 3; j++)
                sum = (sum + dp[n][i][j]) % md;
        return sum;
    }
};

int main()
{
    Solution sol;
    sol.checkRecord(4);
    return 0;
}