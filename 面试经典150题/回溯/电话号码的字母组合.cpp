class Solution {
public:
    vector<vector<string>> tb = {{"a", "b", "c"}, {"d", "e", "f"}, {"g", "h", "i"}, {"j", "k", "l"},
                        {"m", "n", "o"}, {"p", "q", "r", "s"}, {"t", "u", "v"}, 
                        {"w", "x", "y", "z"}};
    vector<string> letterCombinations(string digits) 
    {
        
        vector<string> res;
        if(digits.empty())
            return res;
        string curStr;
        sub(res, curStr, 0, digits);
        return res;
    }

    void sub(vector<string> &res, string curStr, int ind, string &digits)
    {
        if(ind == digits.size())
        {
            res.emplace_back(curStr);
            return;
        }
        for(int i = 0; i < tb[digits[ind] - '2'].size(); i++)
        {
            sub(res, curStr + tb[digits[ind] - '2'][i], ind + 1, digits);
        }
    }
};