#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
using namespace std;

class Solution
{
public:
    /*
        int takeCharacters(string s, int k)
        {
            int left = 0, right = s.size() - 1;
            if (k == 0)
                return 0;
            int res = 0;
            vector<int> tb(3, k);
            while (left <= right)
            {
                if (tb[s[left] - 'a'])
                {
                    tb[s[left] - 'a']--;
                    left++;
                }
                else if (tb[s[right] - 'a'])
                {
                    tb[s[right] - 'a']--;
                    right--;
                }
                else
                {
                    left++;
                    right--;
                }
                if (tb[0] == 0 && tb[1] == 0 && tb[2] == 0)
                    return res + 1;
                res++;
            }

            return -1;
        }
        */
    int takeCharacters(string s, int k)
    {
        if (k == 0)
            return 0;
        vector<int> tb(3, 0);
        for (int i = 0; i < s.size(); i++)
            tb[s[i] - 'a']++;
        if (tb[0] < k || tb[1] < k || tb[2] < k)
            return -1;

        int res = s.size();
        int left = 0, right = 0;
        while(left < s.size())
        {
            if(tb[0] >= k || tb[1] >= k && tb[2] >= k)
                res = min(res, left + 1 + s.size() - right);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    string s = "abccba";
    int k = 1;
    sol.takeCharacters(s, k);
    return 0;
}