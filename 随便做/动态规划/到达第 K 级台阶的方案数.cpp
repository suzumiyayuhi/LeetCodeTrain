class Solution {
public:
    int waysToReachStair(int k) {
        if(k == 0)
            return 2;
        if(k == 1)
            return 4;

        int power = 0;
        int powerSum = 1;
        bool flag = false;
        while(powerSum <= k)
        {
            powerSum = powerSum + (1 << power);
            power++;
            if(powerSum == k)
                flag = true;
        }
        int count = powerSum - k;
        power++;

        if(flag && count > power)
            return 1;
        if(!flag && count > power)
            return 0;
        
        long long res = 1;
        int a = max(power - count, count);
        int b = min(power - count, count);
        
        for(int i = a + 1, tem = 1; i <= power; i++)
        {
            res = res * i / tem;
            tem++;
            
        }

        if(flag)
            return res + 1;
        return res;
    }
};