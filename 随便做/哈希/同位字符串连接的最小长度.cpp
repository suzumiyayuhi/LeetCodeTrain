class Solution {
public:
    int minAnagramLength(string s)
    {
        vector<int> dic(26, 0);
        int res = 0;
        for(int i = 0; i < s.size(); i++)
        {
            dic[s[i] - 'a']++;
            res++;
            if(s.size() % res)
                continue;
            
            int time = 1;
            bool flag = true;
            while(time * res < s.size())
            {
                vector<int> temDic(26, 0);
                for(int j = time * res; j < (time + 1) * res; j++)
                {
                    temDic[s[j] - 'a']++;
                }
                if(temDic != dic)
                {
                    flag = false;
                    break;
                }
                time++;
            }
            if(flag)
                return res;
        }

        return s.size();
    }
};