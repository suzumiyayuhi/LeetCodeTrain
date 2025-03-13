class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        vector<int> leftMax(n, 0);
        leftMax[0] = nums[0];
        vector<int> rightMin(n, 0x3f3f3f);
        rightMin[n - 1] = nums[n - 1];
        for(int i = 1; i < n; i++)
        {
            leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
        }
        for(int i = n - 2; i >= 0; i--)
        {
            rightMin[i] = min(rightMin[i + 1], nums[i + 1]);
        }

        for(int i = 1; i < n - 1; i++)
        {
            if(leftMax[i] < nums[i] && rightMin[i] > nums[i])
            {
                res += 2;
                continue;
            }
            if(nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
            {
                res++;
            }
        }

        return res;
    }
};