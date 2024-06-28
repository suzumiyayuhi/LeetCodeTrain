#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.size();
        string ddd[26];
        unordered_map<string, int> eee;
        int j = 0, k = j;
        for(int i = 0; i < n; i++)
        {
            if(j >= s.size())
                return false;
            string cur = "";
            while(s[k] != ' ' && k < s.size())
                k++;
            cur = s.substr(j, k - j);
            k++;
            j = k;
            if(ddd[pattern[i] - 97] == "" && (eee.find(cur) == eee.end()))
            {
                ddd[pattern[i] - 97] = cur;
                eee[cur] = pattern[i] - 97;
            }
            if(ddd[pattern[i] - 97] != cur || eee[cur] != pattern[i] - 97)
                return false;
        }
        if(j < s.size())
            return false;
        return true;
    }
};

int main()
{
    Solution sol;
    string p = "abba";
    string s = "dog dog dog dog";
    sol.wordPattern(p, s);
    return 0;
}