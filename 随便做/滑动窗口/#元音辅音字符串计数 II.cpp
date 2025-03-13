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
#include <functional>
using namespace std;

/*
class Solution
{
public:
    int countOfSubstrings(string word, int k)
    {
        vector<int> cnt(26, 0);
        int left = 0, right = 0;
        int res = 0;
        while (right < word.size())
        {
            cnt[word[right] - 'a']++;

            int tem = check(cnt);
            if (tem == -1)
            {
                right++;
                continue;
            }

            if (right - left + 1 - tem > k)
            {
                cnt[word[left] - 'a']--;
                cnt[word[right] - 'a']--;
                left++;
                continue;
            }

            if (right - left + 1 - tem == k)
            {
                res++;
            }
            right++;
        }

        cnt[word[left] - 'a']--;
        left++;
        right--;
        while (true)
        {
            int tem = check(cnt);
            if (tem == -1)
                break;
            if (right - left + 1 - tem < k)
                break;
            if (right - left + 1 - tem == k)
            {
                res++;
            }
            cnt[word[left] - 'a']--;
            left++;
        }

        return res;
    }

    int check(vector<int> &cnt)
    {
        if (cnt['a' - 'a'] == 0 || cnt['e' - 'a'] == 0 || cnt['i' - 'a'] == 0 || cnt['o' - 'a'] == 0 || cnt['u' - 'a'] == 0)
            return -1;
        int tem = cnt['a' - 'a'] + cnt['e' - 'a'] + cnt['i' - 'a'] + cnt['o' - 'a'] + cnt['u' - 'a'];
        return tem;
    }
};
*/
class Solution
{
public:
    long long countOfSubstrings(string word, int k)
    {
        return sub(word, k) - sub(word, k + 1);
    }

    long long sub(string &word, int k)
    {
        int n = word.size();
        int left = 0, right = 0;
        vector<int> cnt(26, 0);
        long long res = 0;
        while (left < n)
        {
            while (right < n && (right - left - check(cnt) < k || check(cnt) == -1))
            {
                cnt[word[right] - 'a']++;
                right++;
            }

            if ((right - left - check(cnt)) >= k && check(cnt) != -1)
            {
                // 以[left...right]为前缀的子串都满足
                res += n - right + 1;
            }

            cnt[word[left] - 'a']--;
            left++;
        }
        return res;
    }

    int check(vector<int> &cnt)
    {
        if (cnt['a' - 'a'] == 0 || cnt['e' - 'a'] == 0 || cnt['i' - 'a'] == 0 || cnt['o' - 'a'] == 0 || cnt['u' - 'a'] == 0)
            return -1;
        int tem = cnt['a' - 'a'] + cnt['e' - 'a'] + cnt['i' - 'a'] + cnt['o' - 'a'] + cnt['u' - 'a'];
        return tem;
    }
};

int main()
{
    Solution sol;
    sol.countOfSubstrings("iqeaouqi", 2);
    return 0;
}