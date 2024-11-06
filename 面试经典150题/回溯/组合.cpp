class Solution {
public:
/*
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        
        for(int i = 1; i <= n; i++)
        {
            vector<int> tem;
            tem.emplace_back(i);
            sub(res, tem, i + 1, n, k);
        }
        return res;

    }

    void sub(vector<vector<int>> &res, vector<int> curVec, int ind, int &n, int &k)
    {
        if(curVec.size() == k)
        {
            res.emplace_back(curVec);
            return;
        }
        if(n - ind + 1 + curVec.size() < k)
            return;
            
        for(int i = ind; i <= n; i++)
        {
            curVec.emplace_back(i);
            sub(res, curVec, i + 1, n, k);
            curVec.erase(curVec.end());
        }
    }
    */
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tem(k, 0);
        sub(res, tem, 0, 1, n, k);
        return res;

    }

    void sub(vector<vector<int>> &res, vector<int> &curVec, int bit, int ind, int &n, int &k)
    {
        if(bit == k)
        {
            res.emplace_back(curVec);
            return;
        }
        if(n - ind + 1 + bit < k)
            return;
        for(int i = ind; i <= n; i++)
        {
            curVec[bit] = i;
            sub(res, curVec, bit + 1, i + 1, n, k);
        }
    }
};