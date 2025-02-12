class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = ranges::max(nums);
        int res = 0;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            long long temRes = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                temRes += (nums[i] - 1) / mid;
            }
            if(temRes > maxOperations)
            {
                left = mid + 1;
            }
            else
            {
                res = mid;
                right = mid - 1;
            }
        }
        return res;
    }
};