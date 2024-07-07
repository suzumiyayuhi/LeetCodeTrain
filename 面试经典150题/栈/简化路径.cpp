#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
/*
    string simplifyPath(string path)
    {
        int n = path.size();
        stack<string> ss;
        for (int i = 0; i < n; i++)
        {
            if (path[i] == '.')
            {
                if (i + 1 < n && path[i + 1] == '.')
                {

                    if (i + 2 < n && path[i + 2] != '/')
                    {
                        int j = i + 2;
                        while (j < n && path[j] != '/')
                            j++;
                        ss.push(path.substr(i, j - i));
                        i = j;
                        i--;
                    }
                    else
                    {
                        i++;
                        if (!ss.empty())
                            ss.pop();
                    }
                }
                else if (i + 1 < n && path[i + 1] == '/')
                    continue;
                else
                {
                    int j = i + 1;
                    if(j >= n)
                        break;
                    while (j < n && path[j] != '/')
                        j++;
                    ss.push(path.substr(i, j - i));
                    i = j;
                    i--;
                }
            }
            else if (path[i] == '/')
                continue;
            else
            {
                int j = i + 1;
                while (j < n)
                {
                    if(path[j] == '/' )
                        break;
                    else
                        j++;

                }
                ss.push(path.substr(i, j - i));
                i = j;
                i--;
            }
        }
        string res = "";
        while (!ss.empty())
        {
            res = "/" + ss.top() + res;
            ss.pop();
        }
        if (res.empty())
            return "/";
        return res;
    }
    */
    string simplifyPath(string path)
    {
        int n = path.size();
        stack<string> ss;
        for(int i = 0; i < n; i++)
        {
            while(i < n && path[i] == '/')
                i++;
            int j = i + 1;
            while(j < n && path[j] != '/')
                j++;
            string tem = path.substr(i, j - i);
            i = j;
            if(tem == "..")
            {
                if(!ss.empty())
                    ss.pop();
            }
            else if(tem == ".")
                continue;
            else
                ss.push(tem);
        }
        string res = "";
        while (!ss.empty())
        {
            res = "/" + ss.top() + res;
            ss.pop();
        }
        if (res.empty())
            return "/";
        return res;
    }
};

int main()
{
    Solution sol;
    string ss = "/a/../../b/../c//.//";
    cout << sol.simplifyPath(ss) << endl;
    return 0;
}