class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int left = 0, right = 0;
        int n = colors.size();
        int res = 0;
        while(right < n)
        {
            
            if(colors[right] != colors[(right + 1) % n])
                right++;
            else
            {
                right++;
                left = right;
            }
            if(right - left + 1 == k)
            {
                left++;
                res++;
            }
        }
        while(left < n)
        {
            if(colors[right % n] != colors[(right + 1) % n])
                right++;
            else
            {
                right++;
                left = right;
            }
            if(right - left + 1 == k)
            {
                left++;
                res++;
            }
        }
        return res;
    }
};