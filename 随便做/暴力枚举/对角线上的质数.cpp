class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) 
    {
        int res = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(isPrime(nums[i][i]))
            {
                res = max(res, nums[i][i]);
            }
            if(isPrime(nums[i][n - 1 - i]))
            {
                res = max(res, nums[i][n - 1 - i]);
            }
        }
        return res;
    }

    bool isPrime(int num)
    {
        if(num == 1)
            return false;
        if(num == 2) 
            return true;
        if(num % 2 == 0) 
            return false;

        for(long long i = 3; i * i <= num; i += 2) 
        {
            if(num % i == 0)
                return false;
        }
        return true;
    }
};