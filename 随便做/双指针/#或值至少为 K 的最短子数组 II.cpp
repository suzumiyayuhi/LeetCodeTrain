class Solution {
public:
/*
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int res = INT_MAX;

        int tem = nums[left];
        while(true)
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
    */
    /*
    int minimumSubarrayLength(vector<int>& nums, int k)
    {
        int res = INT_MAX;
        for(int right = 0; right < nums.size(); right++)
        {
            int tem = nums[right];
            if(tem >= k)
                return 1;
            for(int left = right - 1; left >= 0 && (nums[left] | tem) != nums[left]; left--)
            {
                nums[left] |= tem;
                if(nums[left] >= k)
                    res = min(res, right - left + 1);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
    */

    int minimumSubarrayLength(vector<int>& nums, int k)
    {
        int res = INT_MAX;
        int left = 0, bottom = 0, rightOr = 0;
        for(int right = 0; right < nums.size(); right++)
        {
            rightOr |= nums[right];
            while(left <= right && (nums[left] | rightOr) >= k)
            {
                res = min(res, right - left + 1);
                left++;
                if(bottom < left)
                {
                    for(int i = right - 1; i >= left; i--)
                    {
                        nums[i] |= nums[i + 1];
                    }
                    bottom = right;
                    rightOr = 0;
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }  
};