class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int res = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int count0 = 0;
            int count1 = 0;
            for(int j = i; j < s.size(); j++)
            {
                s[j] == '0' ? ++count0 : ++count1;
                if(count0 <= k || count1 <= k)
                {
                    res++;
                }
                else
                    break;
            }
        }
        return res;
    }
};