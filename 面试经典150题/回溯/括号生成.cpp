class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> res;
        string tem = "";
        sub(n, 0, 0, tem, res);
        return res;
    }

    void sub(int& n, int leftN, int rightN, string tem, vector<string>& res)
    {
        if(leftN < rightN || leftN > n)
            return;
        if(leftN + rightN == 2 * n)
        {
            res.emplace_back(tem);
            return;
        }
        sub(n, leftN + 1, rightN, tem + "(", res);
        sub(n, leftN, rightN + 1, tem + ")", res);
    }
};