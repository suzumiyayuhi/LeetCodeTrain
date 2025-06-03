class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        int res = 0x3f3f3f, left = 0, right = m;
        while(left <= right)
        {
            vector<int> diff(n + 1);
            int temRes = (left + right) / 2;
            for(int i = 0; i < temRes; i++)
            {
                diff[queries[i][0]] += queries[i][2];
                diff[queries[i][1] + 1] -= queries[i][2];
            }

            int prefixSum = 0;
            bool flag = true;
            for(int i = 0; i < n; i++)
            {
                prefixSum += diff[i];
                if(nums[i] > prefixSum)
                {
                    left = temRes + 1;
                    flag = false;
                    break;
                }
            }
            if(!flag)
                continue;
            res = min(res, temRes);
            right = temRes - 1;
        }
        return res == 0x3f3f3f ? -1 : res;
    }
};