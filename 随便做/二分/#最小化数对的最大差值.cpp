class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums[0];
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(check(nums, mid, p))
                right = mid;
            else
                left = mid + 1;
        }
        return left;

    }

    bool check(vector<int>& nums, int val, int p)
    {
        int cnt = 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i + 1] - nums[i] <= val)
            {
                cnt++;
                i++;
            }
        }
        return cnt >= p;
    }
};