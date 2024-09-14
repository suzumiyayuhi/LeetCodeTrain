class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        vector<int> res(nums.size(), 0);

        while(left <= right)
        {
            int a = nums[left] * nums[left];
            int b = nums[right] * nums[right];
            if(a > b)
            {
                res[right - left] = a;
                left++;
            }
            else
            {
                res[right - left] = b;
                right--;
            }
        }
        return res;
    }
};