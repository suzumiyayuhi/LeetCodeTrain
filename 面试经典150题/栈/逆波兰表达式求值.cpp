#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        int n = tokens.size();
        stack<int> sss;
        for (int i = 0; i < n; i++)
        {
            auto tem = tokens[i];
            int a, b;
            switch (tem[0])
            {
            case '+':
                a = sss.top();
                sss.pop();
                b = sss.top();
                sss.pop();
                sss.push(b + a);
                break;

            case '-':
                if (tem.size() == 1)
                {
                    a = sss.top();
                    sss.pop();
                    b = sss.top();
                    sss.pop();
                    sss.push(b - a);
                }
                else
                {
                    int sum = 0;
                    for (int j = 1; j < tem.size(); j++)
                        sum = sum * 10 + (tem[j] - 48);
                    sss.push(-sum);
                }
                break;

            case '*':
                a = sss.top();
                sss.pop();
                b = sss.top();
                sss.pop();
                sss.push(b * a);
                break;

            case '/':
                a = sss.top();
                sss.pop();
                b = sss.top();
                sss.pop();
                sss.push(b / a);
                break;

            default:
                int sum = 0;
                for (int j = 0; j < tem.size(); j++)
                    sum = sum * 10 + (tem[j] - 48);
                sss.push(sum);
                break;
            }
        }
        return sss.top();
    }
};

int main()
{
    vector<string> dd = {"4", "13", "5", "/", "+"};
    Solution sol;
    cout << sol.evalRPN(dd);
    return 0;
}