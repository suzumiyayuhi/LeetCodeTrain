class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int mx = ranges::max(arr), res = 0;
        vector<int> pre(mx + 2);
        for(int j = 0; j < n; j++)
        {
            int y = arr[j];
            for(int k = j + 1; k < n; k++)
            {
                int z = arr[k];
                if(abs(y - z) > b)
                    continue;
                int l = max({y - a, z - c, 0});
                int r = min({y + a, z + c, mx});
                res += max(pre[r + 1] - pre[l], 0);
            }
            for(int v = y + 1; v < mx + 2; v++)
                pre[v]++;
        }


        return res;
    }
};