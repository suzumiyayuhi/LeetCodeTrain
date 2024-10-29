class Solution {
public:
    vector<string> validStrings(int n) 
    {
        vector<string> res;
        string str1 = "1";
        string str2 = "0";
        sub(res, 1, n, str1);
        sub(res, 1, n, str2);
        return res;
    }

    void sub(vector<string> &res, int cur, int n, string str)
    {
        if(cur == n)
        {
            res.emplace_back(str);
            return;
        }
        sub(res, cur + 1, n, str + "1");
        if(str[str.size() - 1] != '0')
            sub(res, cur + 1, n, str + "0");
        
    }
};