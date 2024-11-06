#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
using namespace std;

class Solution
{
public:
    /*
        vector<int> resultsArray(vector<int> &nums, int k)
        {
            if (k == 1)
                return nums;
            vector<int> res;
            int left = 0, right = 1;
            int n = nums.size();
            while (right < n)
            {
                if (right - left == k)
                {
                    res.emplace_back(nums[right - 1]);
                    left++;
                }
                else
                {
                    if (nums[right - 1] + 1 == nums[right])
                        right++;
                    else
                    {
                        right++;
                        while (left != right)
                        {
                            res.emplace_back(-1);
                            left++;
                        }
                    }
                }
            }

            int count = res.size() - n + k;
            for(int i = 0; i < count; i++)
                res.emplace_back(-1);
            return res;
        }
        */
    /*
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        if (k == 1)
            return nums;
        int n = nums.size();
        int left = 0, right = 0;
        vector<int> res(n - k + 1, -1);
        while (right < n)
        {
            if (right - left + 1 == k)
            {
                res[left] = nums[right];
                left++;
            }
            else
            {
                if (nums[right + 1] - 1 == nums[right])
                    right++;
                else
                {
                    right++;
                    while (left != right)
                    {
                        left++;
                    }
                }
            }
        }
        return res;
    }
    */
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        if (k == 1)
            return nums;
        int n = nums.size();
        int left = 0, right = 0;
        vector<int> res(n - k + 1, -1);
        while (right < n - 1)
        {

            if (nums[right + 1] - 1 == nums[right])
                right++;
            else
            {
                right++;
                while (left != right)
                {
                    left++;
                }
            }
            if (right - left + 1 == k)
            {
                res[left] = nums[right];
                left++;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> ss = {1, 2, 3, 4, 3, 2, 5};
    Solution sol;
    sol.resultsArray(ss, 3);
    return 0;
}