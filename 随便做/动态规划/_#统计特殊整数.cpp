class Solution {
public:
    unordered_map<int, int> memo;
    int countSpecialNumbers(int n) 
    {
        string strNum = to_string(n);
        int bitNum = strNum.size();

        int res = 0;
        int tem = 9;
        for(int i = 0; i < bitNum - 1; i++)
        {
            res += tem;
            tem = (9 - i) * tem;
        }
        res += sub(0, false, strNum);
        return res;
    }

    int sub(int mask, bool prefixSmaller, string strNum)
    {
        if(__builtin_popcount(mask) == strNum.size())
        {
            return 1;
        }
        int key = (mask << 1) + (prefixSmaller ? 1 : 0);
        if(!memo.count(key))
        {
            int res = 0;
            int lowBound = mask == 0 ? 1 : 0;
            int upBound = prefixSmaller ? 9 : strNum[__builtin_popcount(mask)] - '0';
            for(int i = lowBound; i <= upBound; i++)
            {
                if(((mask >> i) & 1) == 0)
                {
                    res += sub(mask | (1 << i), prefixSmaller || i < upBound, strNum);
                }
            }
            memo[key] = res;
        }
        return memo[key];
    }
};