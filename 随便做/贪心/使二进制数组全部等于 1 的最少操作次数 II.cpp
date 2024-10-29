#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
/*
    int minOperations(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                count++;
                for(int j = i; j < nums.size(); j++)
                    nums[j] = nums[j] == 0 ? 1 : 0;
            }
        }

        return count;
    }
    */
    int minOperations(vector<int>& nums)
    {
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                count++;
                nums[i] = 1;
                while(i + 1 < nums.size())
                {
                    if(nums[i + 1] == 0)
                    {
                        nums[i + 1] = 1;
                        i++;
                    }
                    else
                    {
                        count++;
                        i++;
                        break;
                    }
                }

            }
        }

        return count;
    }
};

int main()
{
    Solution sol;
    vector<int> vv = {0,0,1,0,0,0};
    sol.minOperations(vv);
    return 0;
}