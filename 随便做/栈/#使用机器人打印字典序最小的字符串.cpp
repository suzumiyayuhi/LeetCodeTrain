class Solution {
public:
    string robotWithString(string s) {
        vector<int> tb(26, 0);
        for(int i = 0; i < s.size(); i++)
        {
            tb[s[i] - 'a']++;
        }

        string res;
        stack<char> temSt;
        for(int i = 0, j = 0; i < s.size(); i++)
        {
            tb[s[i] - 'a']--;
            temSt.push(s[i]);

            while(j <= 25 && tb[j] == 0)
                j++;

            while(!temSt.empty() && temSt.top() - 'a' <= j)
            {
                res += temSt.top();
                temSt.pop();
            }
            
        }
        return res;
    }
};