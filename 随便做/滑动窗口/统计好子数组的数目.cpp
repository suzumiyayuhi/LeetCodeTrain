class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        int left = 0, right = 0;
        int n = nums.size();
        long long res = 0;
        int curK = 0;
        while(right < n || curK >= k)
        {
            if(curK >= k)
            {
                res += n - right + 1;
                if(um[nums[left]] >= 2)
                    curK -= sub(um[nums[left]]);
                um[nums[left]]--;
                if(um[nums[left]] >= 2)
                    curK += sub(um[nums[left]]);
                left++;
            }
            else
            {
                if(um[nums[right]] >= 2)
                    curK -= sub(um[nums[right]]);
                um[nums[right]]++;
                if(um[nums[right]] >= 2)
                    curK += sub(um[nums[right]]);
                right++;
            }
                
        }
        return res;
    }

    int sub(int cur)
    {
        return cur * (cur - 1) / 2;
    }
};