class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> um;

    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++)
        {
            um[arr[i]].emplace_back(i);
        }    
    }
    
    int query(int left, int right, int value) {
        vector<int>& tem = um[value];
        if(tem.empty())
            return 0;
        int l1 = 0, r1 = tem.size() - 1, res1 = -1;
        while(l1 <= r1)
        {
            int m = (l1 + r1) / 2;
            if(tem[m] < left)
            {
                l1 = m + 1;
            }
            else
            {
                r1 = m - 1;
                res1 = m;
            }
        }

        int l2 = 0, r2 = tem.size() - 1, res2 = -1;
        while(l2 <= r2)
        {
            int m = (l2 + r2) / 2;
            if(tem[m] <= right)
            {
                l2 = m + 1;
                res2 = m;
            }
            else
            {
                r2 = m - 1;
            }
        }

        if(res1 == -1 || res2 == -1)
            return 0;
        return res2 - res1 + 1;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */