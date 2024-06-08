#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:

    int subCal(string s, int& i)
    {
        stack<char> oper;
        stack<int> num;
        int offset = 0;
        while (offset < s.size())
        {

            if (s[offset] == '(')
            {
                num.push(subCal(s.substr(offset + 1, s.size() - offset + 1), offset));
                offset++;
            }
            else if (s[offset] == ')')
            {
                offset++;
                break;
            }
            else if (s[offset] >= '0' && s[offset] <= '9')
            {
                int j = offset;
                while (s[j] >= '0' && s[j] <= '9')
                    j++;
                int tem = stoi(s.substr(offset, j - offset));
                num.push(tem);
                offset = j;
            }
            else if (s[offset] == ' ')
            {
                offset++;
            }
            else
            {
                oper.push(s[offset]);
                offset++;
            }
        }

        while (!oper.empty())
        {
            char temOper = oper.top();
            oper.pop();
            int a = num.top();  num.pop();
            if (oper.empty())
            {
                if (num.empty())
                    num.push(-a);
                else
                {
                    int b = num.top();
                    num.pop();
                    if (temOper == '+')
                        num.push(b + a);
                    else if (temOper == '-')
                        num.push(b - a);
                }
            }
            else
            {
                int b = num.top();  num.pop();
                if (oper.top() == '-')
                {
                    if (temOper == '+')
                        num.push(b - a);
                    else if (temOper == '-')
                        num.push(b + a);
                }
                else if (oper.top() == '+')
                {
                    if (temOper == '+')
                        num.push(b + a);
                    else if (temOper == '-')
                        num.push(b - a);
                }
            }
        }
        i += offset;
        return num.top();
    }

    int calculate(string s) 
    {
        int i = 0;
        return subCal(s, i);
    }
};

int main()
{
    string s = "(1+(4+5+2)-3)+(6+8)";
    Solution sol;
    cout << sol.calculate(s) << endl;
    return 0;
}