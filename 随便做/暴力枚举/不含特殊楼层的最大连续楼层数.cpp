class Solution {
public:
/*
    int maxConsecutive(int bottom, int top, vector<int>& special) 
    {
        int res = 0;
        sort(special.begin(), special.end());
        int i = bottom, j = 0;
        int tem = 0;
        while(i <= top)
        {
            if(j >= special.size())
                break;
            if(special[j] != i)
            {
                tem++;
            }
            else
            {
                res = max(res, tem);
                j++;
                tem = 0;
            }
            i++;
        }
        return max(res, top - i + 1);
    }
*/
    int maxConsecutive(int bottom, int top, vector<int>& special) 
    {
        sort(special.begin(), special.end());
        int res = (special[0] - bottom);
        for(int i = 0; i < special.size() - 1; i++)
        {
            res = max(res, special[i + 1] - special[i] - 1);
        }
        res = max(res, top - special[special.size() - 1]);
        return res;
    }
};