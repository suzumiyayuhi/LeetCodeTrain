class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int res = INT_MAX;

        int tem = nums[left];
        while(right < nums.size())
        {
            if(tem < k)
            {
                right++;
                if(right >= nums.size())
                    return res == INT_MAX ? -1 : res;
                tem = tem | nums[right];
            }
            else
            {
                res = min(res, right - left + 1);
                left++;
                if(left > right)
                    return res;
                tem = 0;
                for(int i = left; i <= right; i++)
                {
                    tem = tem | nums[i];
                }
            }
        }
        return res;
    }
};