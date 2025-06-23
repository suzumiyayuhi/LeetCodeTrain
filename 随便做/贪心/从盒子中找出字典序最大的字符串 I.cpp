class Solution {
public:
    string answerString(string word, int numFriends) {
        char maxHead = 'a';
        int n = word.size();
        if(numFriends == 1)
            return word;
        for(int i = 0; i < n; i++)
        {
            maxHead = max(word[i], maxHead);
        }

        string res;
        for(int i = 0; i < n; i++)
        {
            if(word[i] != maxHead)
                continue;
            int tem = numFriends - i - 1 >= 0 ? numFriends - i - 1 : 0;
            string temRes;
            temRes += word[i];
            for(int j = i + 1; j < n - tem; j++)
            {
                temRes += word[j];
            }

            if(res.empty())
                res = temRes;
            else
            {
                if(!cmpBigger(res, temRes))
                    res = temRes;
            }
        }

        
        return res;
    }

    bool cmpBigger(string str1, string str2)
    {
        int n = str1.size(), m = str2.size();
        int temSz = min(n, m);
        for(int i = 0; i < temSz; i++)
        {
            if(str1[i] == str2[i])
                continue;
            if(str1[i] > str2[i])
                return true;
            else
                return false;
        }
        if(n > m)
            return true;
        else
            return false;
    }
};