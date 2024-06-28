#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> oriHash;
        unordered_map<char, int> hashStr;
        for (int i = 0; i < t.size(); i++)
        {
            oriHash[t[i]]++;
            hashStr[t[i]]++;
        }

        string res = "";
        int len = 0x3f3f3f;
        int i = 0, j = 0;
        if (s.size() == 0 || t.size() == 0)
            return res;

        while (j <= s.size())
        {
            auto temd = oriHash.find(s[j]);
            if (temd == oriHash.end())
            {
                j++;
            }
            else
            {
                --(temd->second);
                if (hashStr.find(s[j]) != hashStr.end())
                {
                    if (--hashStr[s[j]] == 0)
                    {
                        hashStr.erase(s[j]);
                    }
                }

                j++;
            }

            if (hashStr.empty())
            {

                while (true)
                {
                    auto tem = oriHash.find(s[i]);
                    if (tem == oriHash.end())
                        i++;
                    else if (tem->second < 0)
                    {
                        (tem->second)++;
                        i++;
                    }
                    else
                        break;
                }

                if (len > j - i)
                {
                    len = j - i;
                    res = s.substr(i, len);
                }
                
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    string s = "ab";
    string t = "b";
    cout << sol.minWindow(s, t) << endl;
    return 0;
}