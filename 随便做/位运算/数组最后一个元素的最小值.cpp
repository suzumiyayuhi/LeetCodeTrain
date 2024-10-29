class Solution {
public:
/*
    long long minEnd(int n, int x)
    {
        long long res = x;
        for(int i = 1; i < n; i++)
        {
            res++;
            while((res & x) != x)
                res++;
        }
        return res;
    }
    */
    long long minEnd(int n, int x)
    {
        if(n == 1)
            return x;
        long long temX = x;
        long long temN = n - 1;
        long long res = x;
        int xBitNum = 32 - __builtin_clz(temX);
        int nBitNum = 32 - __builtin_clz(temN);
        int i = 0, j = 0;
        while (j < nBitNum)
        {
            if (((temX >> i) & 1) == 0)
            {
                if (((temN >> j) & 1) != 0)
                    res += (1LL << i);
                j++;
            }
            i++;
        }
        return res;
    }
};