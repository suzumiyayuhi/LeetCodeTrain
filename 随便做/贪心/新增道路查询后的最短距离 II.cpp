class Solution {
public:
/*
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) 
    {
        vector<int> res;
        vector<int> uni(n);
        int temRes = n - 1;
        for(int i = 0; i < queries.size(); i++)
        {
            for(int j = queries[i][0] + 1; j < queries[i][1]; j++)
            {
                if(uni[j] == 0)
                {
                    temRes--;
                    uni[j] = 1;
                }
            }
            res.emplace_back(temRes);
        }
        return res;
    }
    */
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries)
    {
        vector<int> res;
        vector<int> nex(n - 1);
        for(int i = 0; i < nex.size(); i++)
        {
            nex[i] = i + 1;
            
        }
        //iota(nex.begin(), nex.end(), 1);
        int temRes = n - 1;
        for(int i = 0; i < queries.size(); i++)
        {
            int left = queries[i][0], right = queries[i][1];
            if(nex[left] && nex[left] < right)
            {
                for(int j = nex[left]; j < right;)
                {
                    temRes--;
                    int tem = nex[j];
                    nex[j] = 0;
                    j = tem;
                }
                nex[left] = right;
            }

            res.emplace_back(temRes);
        }
        return res;
    }
};