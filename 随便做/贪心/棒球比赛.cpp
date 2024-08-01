class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> ss;
        for(int i = 0; i < operations.size(); i++)
        {
            auto tem = operations[i][0];
            if(tem >= '0' && tem <= '9')
            {
                ss.push(stoi(operations[i]));
            }
            else if(tem == '-')
            {
                ss.push(-stoi(operations[i].substr(1)));
            }
            else if(tem == 'C')
            {
                ss.pop();
            }
            else if(tem == 'D')
            {
                int x = ss.top();
                ss.push(2 * x);
            }
            else
            {
                int a = ss.top();
                ss.pop();
                int b = ss.top();
                ss.push(a);
                ss.push(a + b);
            }
        }
        int res = 0;
        while(!ss.empty())
        {
            res += ss.top();
            ss.pop();
        }
        return res;
    }
    
};