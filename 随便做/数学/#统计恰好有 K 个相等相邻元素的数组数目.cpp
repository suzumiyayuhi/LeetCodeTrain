const int MX = 1e5;
const int MOD = 1e9 + 7;

class Solution {
public:
    vector<long long> fact;
    vector<long long> inv_fact;

    int countGoodArrays(int n, int m, int k) {
        init(n);
        long long tem = quickPow(m - 1, n - 1 - k) * m % MOD;
        return sub(n - 1, k) * tem % MOD;
    }
    
    void init(int n)
    {
        fact = vector<long long>(n);
        inv_fact = vector<long long>(n);
        
        fact[0] = 1;
        for(int i = 1; i < n; i++)
        {
            fact[i] = fact[i - 1] * i % MOD;
        }

        inv_fact[n - 1] = quickPow(fact[n - 1], MOD - 2);
        for(int i = n - 1; i > 0; i--)
        {
            inv_fact[i - 1] = inv_fact[i] * i % MOD;
        }
    }

    long long sub(int n, int m)
    {
        return fact[n] * inv_fact[m] % MOD * inv_fact[n - m] % MOD;
    }

    long long quickPow(long long x, int n)
    {
        long long res = 1;
        while(n)
        {
            if(n & 1)
            {
                res = res * x % MOD;
            }
            x = x * x % MOD;
            n >>= 1;
        }
        return res;
    }
};