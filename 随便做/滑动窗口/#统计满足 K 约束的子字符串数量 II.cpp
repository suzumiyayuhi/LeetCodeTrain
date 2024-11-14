class Solution
{
public:
    /*
vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>> &queries)
{
    int n = s.size();
    vector<long long> prefix(n + 1, 0);
    vector<int> count(2, 0);
    int temLeft = 0;
    for (int i = 0; i < s.size(); i++)
    {
        count[s[i] - '0']++;
        while (count[0] > k && count[1] > k)
        {
            count[s[temLeft] - '0']--;
            temLeft++;
        }
        prefix[i + 1] = prefix[i] + i - temLeft + 1;
    }

    vector<long long> res;
    for (int i = 0; i < queries.size(); i++)
    {
        int left = queries[i][0];
        int right = queries[i][1];
        if (left)
            res.emplace_back(prefix[right + 1] - prefix[left + 1]);
        else
            res.emplace_back(prefix[right + 1] - prefix[left + 1] + 1);
    }
    return res;
}
    */
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>> &queries)
    {
        int n = s.size();
        vector<long long> prefix(n + 1, 0);
        vector<int> vecLeft(n, 0);
        vector<int> count(2, 0);
        int temLeft = 0;
        for (int i = 0; i < s.size(); i++)
        {
            count[s[i] - '0']++;
            while (count[0] > k && count[1] > k)
            {
                count[s[temLeft] - '0']--;
                temLeft++;
            }
            prefix[i + 1] = prefix[i] + i - temLeft + 1;
            vecLeft[i] = temLeft;
        }

        vector<long long> res;
        for (int i = 0; i < queries.size(); i++)
        {
            int left = queries[i][0];
            int right = queries[i][1];
            int temLeft = lower_bound(vecLeft.begin() + left, vecLeft.begin() + right + 1, left) - vecLeft.begin();
            res.emplace_back((long long)(temLeft - left) * (temLeft - left + 1) / 2 + prefix[right + 1] - prefix[temLeft]);
        }
        return res;
    }
};

