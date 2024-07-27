#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = s.size();
        int i = 0;
        while(k != 0)
        {
            if(i == n)
                break;
            int offset = 0;
            while(s[i] - 97 - offset > k)
            {
                offset++;
                if(s[i] - 97 - offset == 0)
                    break;
            }
            int tem = -(s[i] - 97 - 26);
            
            if(tem <= k && tem < s[i] - 97)
            {
                s[i] = 97;
                k -= tem;
            }
            else
            {
                k -= s[i] - 97 - offset;
                s[i] = 97 + offset;
            }
                
            i++;
        }
        return s;
    }
};

int main()
{
    //string s = "zbbz";
    string s = "rn";
    Solution sol;
    cout << sol.getSmallestString(s, 9);
    return 0;
}