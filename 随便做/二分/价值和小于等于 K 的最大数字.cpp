#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long getPeriodPrice(long long num, int x)
    {
        long long period = 1LL << x;
        //计算完整的周期提供的价值
        long long res = (num + 1) / period * pow(2, x - 1);
        //计算不完整的周期提供的价值
        if((num + 1) % period >= (period >> 1))
            res += (num + 1) % period - (period >> 1);   
        return res;
    }

    long long getAccuPrice(long long num, int x)
    {
        int bitNum = 0;
        long long tem = num;
        while(tem)
        {
            tem = tem >> 1;
            bitNum++;
        }

        long long res = 0;
        for(int i = x; i <= bitNum; i += x)
        {
            res += getPeriodPrice(num, i);
        }
        return res;
    }

    long long findMaximumNumber(long long k, int x) {
        long long left = 1, right = (k + 1) << x;

        while(left < right)
        {
            long long mid = (left + right + 1) / 2;
            long long a = getAccuPrice(mid, x);
            if(a > k)
            {
                right = mid - 1;
            }
            else
            {
                left = mid;
            }
        }
        return left;
    }
};

int main()
{
    Solution sol;
    sol.findMaximumNumber(7, 2);
    return 0;
}