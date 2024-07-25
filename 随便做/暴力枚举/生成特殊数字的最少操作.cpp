class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();
        if(n == 1)
            return num[0] == '0'? 0 : 1;
        int res = n;
        if(num[n - 1] == '0')
            res = n - 1;
        int left = n - 2;
        while(left >= 0)
        {
            int right = n - 1;
                
            switch(num[left])
            {
                case '2':
                while(right > left)
                {
                    if(num[right] == '5')
                        res = min(res, right - left - 1 + n - 1 - right);
                    right--;
                }
                break;

                case '5':
                while(right > left)
                {
                    if(num[right] == '0')
                        res = min(res, right - left - 1 + n - 1 - right);
                    right--;
                }
                break;

                case '7':
                while(right > left)
                {
                    if(num[right] == '5')
                        res = min(res, right - left - 1 + n - 1 - right);
                    right--;
                }
                break;

                case '0':
                res = min(res, n - 1);
                while(right > left)
                {
                    if(num[right] == '0')
                        res = min(res, right - left - 1 + n - 1 - right);
                    right--;
                }
            }
            left--;
        }
        return res;
    }
};