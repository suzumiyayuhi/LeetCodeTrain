class Solution {
public:
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        int n = digits.size();
        vector<int> res;

        unordered_map<int, int> um;
        for (int i = 0; i < n; i++)
        {
            um[digits[i]]++;
        }

        for (auto tem1 : um)
        {
            if (tem1.first % 2)
                continue;
            int temRes = tem1.first;
            um[tem1.first]--;
            for (auto tem2 : um)
            {
                if (um[tem2.first] == 0)
                    continue;

                um[tem2.first]--;
                temRes += tem2.first * 10;
                for (auto tem3 : um)
                {
                    if (tem3.first && um[tem3.first])
                    {
                        temRes += tem3.first * 100;
                        res.emplace_back(temRes);
                        temRes -= tem3.first * 100;
                    }
                }
                temRes -= tem2.first * 10;
                um[tem2.first]++;
            }
            um[tem1.first]++;
            temRes -= tem1.first;
            
        }

        sort(res.begin(), res.end());
        return res;
    }
};