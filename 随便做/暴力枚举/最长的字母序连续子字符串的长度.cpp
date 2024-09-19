class Solution {
public:
    int longestContinuousSubstring(string s) {
        int res = 1;
        for(int i = 0; i < s.size() - 1; i++)
        {
            int temRes = 1;
            while(i < s.size() && s[i] == s[i + 1] - 1)
            {
                temRes++;
                i++;
            }
            res = max(temRes, res);
        }
        return res;
    }
};