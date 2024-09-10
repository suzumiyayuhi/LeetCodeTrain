#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    /*
        int maximumLength(vector<int> &nums, int k)
        {
            int n = nums.size();
            vector<vector<int>> dp(n, vector<int>(k + 1, -1));
            int res = 1;
            for (int i = 0; i < n; i++)
            {
                dp[i][0] = 1;
                for (int j = 0; j <= k; j++)
                {
                    for (int x = 0; x < i; x++)
                    {
                        if (nums[i] == nums[x])
                        {
                            dp[i][j] = max(dp[i][j], dp[x][j] + 1);
                        }
                        else
                        {
                            if (j)
                            {
                                dp[i][j] = max(dp[x][j - 1] + 1, dp[i][j]);
                            }
                        }
                        res = max(res, dp[i][j]);
                    }
                }
            }
            return res;
        }*/
    /*
        int maximumLength(vector<int> &nums, int k)
        {
            int n = nums.size();
            int res = 1;
            unordered_map<int, vector<int>> dp;
            for (int i = 0; i < n; i++)
            {
                vector<int> temVec;
                if (dp.find(nums[i]) == dp.end())
                {
                    temVec = vector<int>(k + 1, 0);
                    temVec[0] = 1;
                }
                else
                {
                    temVec = dp[nums[i]];
                }

                for (auto tem : dp)
                {
                    for (int j = 0; j <= k; j++)
                    {
                        if (nums[i] == tem.first)
                        {
                            if (dp[tem.first][j])
                                temVec[j] = max(temVec[j], dp[tem.first][j] + 1);
                            res = max(res, temVec[j]);
                        }
                        else
                        {
                            if (j)
                            {
                                if (dp[tem.first][j - 1])
                                    temVec[j] = max(dp[tem.first][j - 1] + 1, temVec[j]);
                            }
                        }
                        res = max(res, temVec[j]);
                    }
                }
                dp[nums[i]] = temVec;
            }
            return res;
        }
        */
    int maximumLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        int res = 1;
        vector<int> sub(k + 1, 0);
        unordered_map<int, vector<int>> dp;
        for (int i = 0; i < n; i++)
        {
            vector<int> temVec;
            if (dp.find(nums[i]) == dp.end())
            {
                temVec = vector<int>(k + 1, 0);
            }
            else
            {
                temVec = dp[nums[i]];
            }

            for (int j = 0; j <= k; j++)
            {
                temVec[j]++;
                if(j)
                {
                    temVec[j] = max(temVec[j], sub[j - 1] + 1);
                }
            }
            dp[nums[i]] = temVec;

            for(int j = 0; j <= k; j++)
            {
                sub[j] = max(sub[j], dp[nums[i]][j]);
                res = max(res, sub[j]);
            }
                
        }
        return res;
    }
};

int main()
{
    vector<int> dd = {1, 2, 1, 1, 3};
    Solution sol;
    sol.maximumLength(dd, 2);
    return 0;
}