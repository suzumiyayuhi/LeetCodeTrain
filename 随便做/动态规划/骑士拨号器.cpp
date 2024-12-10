class Solution {
public:
    int knightDialer(int n) {
        if(n == 1)
            return 10;

        int MOD = 1e9 + 7;
        vector<vector<int>> tb = {
            {4, 6},
            {8, 6}, {7, 9}, {4, 8},
            {3, 9, 0}, {}, {1, 7, 0},
            {2, 6}, {1, 3}, {4, 2}
        };

        vector<int> vec1(10, 1);
        vector<int> vec2(10, 0);
        vec1[5] = 0;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                for(int k = 0; k < tb[j].size(); k++)
                {
                    vec2[tb[j][k]] = (vec2[tb[j][k]] + vec1[j]) % MOD;
                }
            }
            vec1 = vec2;
            vec2.clear();
            vec2.resize(10);
        }

        int res = 0;
        for(int i = 0; i < 10; i++)
        {
            res = (res + vec1[i]) % MOD;
        }
        return res;
    }
};