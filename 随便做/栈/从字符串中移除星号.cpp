class Solution
{
public:
    string removeStars(string s)
    {
        string res = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '*')
            {
                res.erase(res.size() - 1);
            }
            else
                res += s[i];
        }
        return res;
    }
};