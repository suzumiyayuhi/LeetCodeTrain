class Solution {
public:
/*
    long long maximumOr(vector<int>& nums, int k)
    {
        long long res = 0;
        int n = nums.size();
        vector<long long> prefix(n, 0);
        vector<long long> suffix(n, 0);

        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] | nums[i - 1];
            suffix[n - 1 - i] = suffix[n- i] | nums[n- i];
        }

        for (int i = 0; i < n; i++)
        {
            long long tem = prefix[i] | suffix[i] | ((long long)nums[i] << k);
            res = max(res, tem);
        }
        return res;
    }
*/
    long long maximumOr(vector<int>& nums, int k)
    {
        long long res = 0;
        long long oneBits = 0, multiBits = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            multiBits = multiBits | (oneBits & nums[i]);
            oneBits = oneBits | nums[i];
        }
        for(int i = 0; i < nums.size(); i++)
        {
            res = max(res, multiBits | (nums[i] << k) | (nums[i] ^ oneBits));
        }

        return res;
    }
};