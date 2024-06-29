class Solution {
public:
    bool isValid(string s) {
        stack<char> res;
        int n = s.size();
        unordered_map<char, char> ff;
        ff[')'] = '(';
        ff['}'] = '{';
        ff[']'] = '[';
        for(int i = 0; i < n; i++)
        {
            if(res.empty())
                res.push(s[i]);
            else
            {
                if(res.top() != ff[s[i]])
                    res.push(s[i]);
                else if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                    return false;
                else
                    res.pop();
            }
        }
        return res.empty();
    }
};