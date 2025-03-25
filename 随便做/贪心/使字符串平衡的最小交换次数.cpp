class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        int res = 0;
        int rightCount = 0;
        while(left < n)
        {
            if(s[left] == '[')
            {
                rightCount++;
            }
            else
            {
                if(rightCount)
                {
                    rightCount--;
                }
                else
                {
                    while(s[right] != ']')
                        right--;
                    res++;
                    right--;
                    rightCount++;
                }
            }

            left++;
        }
        return res;
    }
};