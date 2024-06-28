#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        int ss[256] = {};
        int tt[256] = {};
        for(int i = 0; i < s.size(); i++)
        {
            if(ww[s[i]] == 0)
            {
                
            }
                ww[s[i]] = t[i];
            if(ww[s[i]] != t[i] || ww)
                return false;
        }
        return true;
    }
};

int main()
{

}