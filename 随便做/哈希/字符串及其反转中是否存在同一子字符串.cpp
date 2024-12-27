class Solution {
public:
    bool isSubstringPresent(string s) {
        vector<vector<int>> tb(26, vector<int>(26, 0));
        for(int i = 0; i < s.size() - 1; i++)
        {
            tb[s[i] - 'a'][s[i + 1]  - 'a'] = 1;
            if(tb[s[i + 1] - 'a'][s[i] - 'a'])
                return true;
        }
        return false;
    }
};