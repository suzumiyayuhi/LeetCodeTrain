class Solution {
public:
    bool isAnagram(string s, string t) {
        int ss[26] = {};
        int tt[26] = {};
        int n = s.size(), m = t.size();
        if(n != m)
            return false;
        for(int i = 0; i < n; i++)
        {
            ss[s[i] - 97]++;
            tt[t[i] - 97]++;
        }
        for(int i = 0; i < 26; i++)
        {
            if(ss[i] != tt[i])
                return false;
        }
        return true;
    }
};