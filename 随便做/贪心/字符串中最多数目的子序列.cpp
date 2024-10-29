#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

class Solution
{
public:
    /*
        long long maximumSubsequenceCount(string text, string pattern)
        {
            int n = text.size();
            vector<int> sub0(n, 0);
            sub0[0] = text[0] == pattern[0] ? 1 : 0;
            int n1 = text[0] == pattern[1] ? 1 : 0;
            for (int i = 1; i < n; i++)
            {
                sub0[i] = text[i] == pattern[0] ? sub0[i - 1] + 1 : sub0[i] = sub0[i - 1];
                if (text[i] == pattern[1])
                    n1++;
            }
            int n0 = sub0[n - 1];
            long long res = 0;
            for (int i = n - 1; i >= 0; i--)
            {
                if (text[i] == pattern[1])
                    res += sub0[i];
            }

            if (pattern[0] == pattern[1])
                return res;
            return res + max(n1, n0);
        }
    */
    /*
        long long maximumSubsequenceCount(string text, string pattern)
        {
            int n = text.size();
            long long n1 = 0;
            long long n0 = 0;
            long long res = 0;
            for (int i = 0; i < n; i++)
            {
                if(text[i] == pattern[1])
                {
                    n1++;
                    res += n0;
                }
                else if(text[i] == pattern[0])
                {
                    n0++;
                }
            }
            if(pattern[0] == pattern[1])
                return (n1 + 1) * n1 / 2;
            return max(res + n1, res + n0);
        }
        */
    long long maximumSubsequenceCount(string text, string pattern)
    {
        int n = text.size();
        int n1 = 0;
        int n0 = 0;
        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            if (text[i] == pattern[1])
            {
                n1++;
                res += n0;
            }
            if (text[i] == pattern[0])
            {
                n0++;
            }
        }
        return res + max(n1, n0);
    }
};

int main()
{
    string text = "mzyzmhrbgfvtkryzpqoacbwtdpri";
    string pattern = "ty";
    Solution sol;
    sol.maximumSubsequenceCount(text, pattern);
    return 0;
}