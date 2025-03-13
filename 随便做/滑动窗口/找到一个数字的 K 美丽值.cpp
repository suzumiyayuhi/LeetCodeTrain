class Solution
{
public:
    int divisorSubstrings(int num, int k)
    {
        int tem = num;
        string str = "";
        while (tem)
        {
            char temC = tem % 10 + '0';
            str = temC + str;
            tem /= 10;
        }

        int cur = str[0] - '0', res = 0;
        int left = 0, right = 0;
        while (right < str.size())
        {
            if (right - left + 1 == k)
            {
                if (cur != 0 && num % cur == 0)
                {
                    res++;
                }
                cur = cur - (str[left] - '0') * pow(10, right - left);
                left++;
                
            }
            right++;
            cur = cur * 10 + str[right] - '0';
        }
        return res;
    }
};