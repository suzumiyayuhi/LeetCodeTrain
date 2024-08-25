class Solution {
public:
    bool checkRecord(string s) {
        int aCount = 0;
        int count;
        for(int i = 0; i < s.size();)
        {
            switch(s[i])
            {
                case 'A':
                    if(++aCount == 2)
                        return false;
                    i++;
                    break;

                case 'L':
                    count = 1;
                    while(s[++i] == 'L')
                    {
                        if(++count == 3)
                            return false;
                    }
                    break;

                default:
                    i++;
                    break;
            }
        }

        return true;
    }
};