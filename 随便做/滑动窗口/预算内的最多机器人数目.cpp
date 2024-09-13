#include <iostream>
#include <vector>
#include <unordered_map>
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
        int maximumRobots(vector<int> &chargeTimes, vector<int> &runningCosts, long long budget)
        {
            int n = chargeTimes.size();
            vector<long long> subSum;

            subSum.emplace_back(0);
            for (int i = 0; i < n; i++)
            {
                subSum.emplace_back(subSum[i] + runningCosts[i]);
            }

            long long curCost = 0;
            int left = 0;
            int maxCharge;
            int res = 0;
            for (int right = 0; right < n; right++)
            {
                curCost = subSum[right + 1] - subSum[left];
                maxCharge = chargeTimes[left];
                for (int i = left + 1; i <= right; i++)
                    maxCharge = max(maxCharge, chargeTimes[i]);
                int temRes = right - left + 1;
                curCost = curCost * temRes + maxCharge;
                if (curCost <= budget)
                {
                    res = max(res, temRes);
                }
                else
                {
                    left++;
                }
            }
            return res;
        }
        */
    /*
 int maximumRobots(vector<int> &chargeTimes, vector<int> &runningCosts, long long budget)
 {
     int n = chargeTimes.size();
     vector<long long> subSum;
     map<int, int> mp;
     subSum.emplace_back(0);
     for (int i = 0; i < n; i++)
     {
         subSum.emplace_back(subSum[i] + runningCosts[i]);
     }

     long long curCost = 0;
     int left = 0;
     int res = 0;
     for (int right = 0; right < n; right++)
     {
         curCost = subSum[right + 1] - subSum[left];
         mp[chargeTimes[right]]++;
         int temRes = right - left + 1;
         curCost = curCost * temRes + (--mp.end())->first;
         if (curCost <= budget)
         {
             res = max(res, temRes);
         }
         else
         {
             if(--mp[chargeTimes[left]] == 0)
                 mp.erase(chargeTimes[left]);
             left++;
         }
     }
     return res;
 }
 */
    int maximumRobots(vector<int> &chargeTimes, vector<int> &runningCosts, long long budget)
    {
        int n = chargeTimes.size();
        vector<long long> subSum;
        deque<int> dq;
        subSum.emplace_back(0);
        for (int i = 0; i < n; i++)
        {
            subSum.emplace_back(subSum[i] + runningCosts[i]);
        }

        long long curCost = 0;
        int left = 0;
        int res = 0;
        for (int right = 0; right < n; right++)
        {
            while (!dq.empty() && chargeTimes[dq.back()] <= chargeTimes[right])
                dq.pop_back();
            dq.push_back(right);

            while (!dq.empty() && (subSum[right + 1] - subSum[left]) * (right - left + 1) + chargeTimes[dq.front()] > budget)
            {
                if (dq.front() == left)
                    dq.pop_front();
                left++;
            }

            if (!dq.empty())
                res = max(res, right - left + 1);
        }
        return res;
    }
};
int main()
{
    Solution sol;
    vector<int> d = {3, 1, 2};
    vector<int> c = {4, 4, 1};
    sol.maximumRobots(c, d, 7);
    return 0;
}

