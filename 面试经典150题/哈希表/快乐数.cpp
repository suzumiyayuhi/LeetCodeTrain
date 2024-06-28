class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> mp;
        while(n != 1)
        {
            if(mp[n] == 1)
                return false;
            int k = 0;
            mp[n] = 1;
            while(n != 0)
            {
                int tem = n % 10;
                k += tem * tem;
                n /= 10;
            }
            n = k;
        }
        return true;
    }
};