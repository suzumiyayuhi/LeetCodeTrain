class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> q;
        for(int i = 0; i < nums.size(); i++)
        {
            q.push(nums[i]);
        }
        int res = 0;
        while(q.size() > 1)
        {
            if(q.top() >= k)
                return res;
            long long a = q.top();
            q.pop();
            long long b = q.top();
            q.pop();
            q.push(a * 2 + b);
            res++;
        }

        return res;
    }
};