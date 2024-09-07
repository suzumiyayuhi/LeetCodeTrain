class Solution {
public:
    string clearDigits(string s)
    {
        string res;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                res.pop_back();
            }
            else
            {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};