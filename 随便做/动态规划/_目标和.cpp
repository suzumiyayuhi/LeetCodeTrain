#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /*
        int findTargetSumWays(vector<int>& nums, int target) {
            int n = nums.size();
            int sum = 0;
            for(int i = 0; i < n; i++)
            {
                sum += nums[i];
            }
            int temTarget = sum - target;
            if(temTarget < 0 || temTarget % 2 != 0)
                return 0;
            temTarget /= 2;

            int **dp = new int*[n + 1];
            for(int i = 0; i < n + 1; i++)
                dp[i] = new int[temTarget + 1]();

            dp[0][0] = 1;
            for(int i = 1; i <= n; i++)
            {
                int curNum = nums[i - 1];
                for(int j = 0; j <= temTarget; j++)
                {
                    dp[i][j] = dp[i - 1][j];
                    if(j >= curNum)
                        dp[i][j] += dp[i - 1][j - curNum];
                }
            }
            int res = dp[n][temTarget];
            for(int i = 0; i < n + 1; i++)
                delete[] dp[i];
            delete[] dp;

            return res;
        }
    */
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        int temTarget = sum - target;
        if (temTarget < 0 || temTarget % 2 != 0)
            return 0;
        temTarget /= 2;

        int *dp = new int [temTarget + 1]();

        for (int i = 1; i <= n; i++)
        {
            int curNum = nums[i - 1];
            dp[0] = 1;
            for (int j = temTarget; j >= 0; j--)
            {
                if (j >= curNum)
                    dp[j] += dp[j - curNum];
            }
        }
        int res = dp[temTarget];

        delete[] dp;

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 1, 2, 1};
    cout << sol.findTargetSumWays(nums, 3);
    return 0;
}