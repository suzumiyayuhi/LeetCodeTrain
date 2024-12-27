struct dicTree
{
    dicTree* node[26];

};

void insert(dicTree* root, string& str)
{
    dicTree* curNode = root;
    for(int i = 0; i < str.size(); i++)
    {
        if(curNode->node[str[i] - 'a'] == NULL)
        {
            curNode->node[str[i] - 'a'] = new dicTree();
        }
        curNode = curNode->node[str[i] - 'a'];
    }
}

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) 
    {
        dicTree* root = new dicTree();
        for(int i = 0; i < words.size(); i++)
        {
            insert(root, words[i]);
        }

        int n = target.size();
        vector<int> dp(n + 1, INT_MAX);
        if(root->node[target[0] - 'a'] == NULL)
            return -1;
        dp[0] = 0;
        
        for(int i = 1; i <= n; i++)
        {
            if(dp[i - 1] == INT_MAX)
                return -1;

            dicTree* tem = root;
            for(int j = i; j <= n; j++)
            {
                if(tem->node[target[j - 1] - 'a'] == NULL)
                    break;
                tem = tem->node[target[j - 1] - 'a'];
                dp[j] = min(dp[i - 1] + 1, dp[j]);
            }
        } 
        return dp[n] == INT_MAX ? -1 : dp[n];

    }
};