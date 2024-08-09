class Solution {
public:
    int findIntegers(int n) {
        vector<int> dp(31);
        dp[0] = 1; dp[1] = 1;
        for(int i = 2; i < 31; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        int res = 0;
        bool flag = false;
        for(int i = 29; i >= 0; i--)
        {
            int val = 1 << i;
            if((val & n) != 0)
            {
                res += dp[i + 1];
                if(flag)
                    break;
                flag = true;
            }
            else
            {
                flag = false;
            }

            if(i == 0)
                res++;
        }
        return res;
    }
};