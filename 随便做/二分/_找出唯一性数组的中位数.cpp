class Solution {
public:
    
    
    bool subFind(int mid, vector<int>& nums)
    {
        int n = nums.size();
        long long k = ((long long) n * (n + 1) / 2 + 1) / 2;
       
        long long count = 0;
        int wL = 0, wR = 0;
        unordered_map<int, int> freq;
        while(wR < n)
        {
            freq[nums[wR]]++;
            while(freq.size() > mid)
            {
                int out = nums[wL++];
                if(--freq[out] == 0)
                    freq.erase(out);
            }
            count += wR - wL + 1;
            if(count >= k)
                return false;
            wR++;
        }
        return true;
    }

    int medianOfUniquenessArray(vector<int>& nums) {
        int n = nums.size();
        
        int left = 0, right = n;
        while(left + 1 < right)
        {
            int mid = (left + right) / 2;
            (subFind(mid, nums) ? left : right) = mid;
        }
        return right;
    }
};