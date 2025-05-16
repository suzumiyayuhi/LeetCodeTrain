class Solution {
public:
    int MOD = 1e9 + 7;

    int lengthAfterTransformations(string s, int t) 
    {
        vector<int> vec(26, 0);
        int res = 0;
        for(int i = 0; i < s.size(); i++)
        {
            vec[s[i] - 'a']++;
        }

        for(int i = 0; i < t; i++)
        {
            vector<int> temVec(26, 0);
            for(int j = 1; j < 26; j++)
            {
                temVec[j] = vec[j - 1] % MOD;
            }
            temVec[0] = vec[25] % MOD;
            temVec[1] += vec[25] % MOD;
            vec = temVec;
        }

        for(int i = 0; i < 26; i++)
        {
            res += vec[i] % MOD;
            res %= MOD;
        }
        return res;
    }
};