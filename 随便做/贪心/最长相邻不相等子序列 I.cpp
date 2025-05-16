class Solution {
public:
    vector<string> getLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        vector<string> res;
        res.emplace_back(words[0]);
        int n = groups.size();
        for(int i = 1; i < n; i++)
        {
            if(groups[i] != groups[i - 1])
                res.emplace_back(words[i]);
        }
        return res;
    }
};