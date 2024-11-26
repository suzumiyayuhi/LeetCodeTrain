class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) 
    {
        int res = 0;
        for(int i = 1; i < colors.size() - 1; i++)
        {
            if(colors[i - 1] != colors[i] && colors[i] != colors[i + 1])
                res++;
        }
        if(colors[0] != colors[colors.size() - 1] && colors[0] != colors[1])
            res++;
        if(colors[0] != colors[colors.size() - 1] && colors[colors.size() - 1] != colors[colors.size() - 2])
            res++;
        return res;
    }
};