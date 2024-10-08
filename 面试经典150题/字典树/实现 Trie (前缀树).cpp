class Trie
{
public:
    Trie *child[26];
    vector<string> vecStr;
    Trie()
    {
        for(int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }

    void insert(string word)
    {
        if (word.size() == 0)
            return;
        Trie *cur = this;
        for (int i = 0; i < word.size(); i++)
        {
            if(cur->child[word[i] - 'a'] == NULL)
                cur->child[word[i] - 'a'] = new Trie();
            cur = cur->child[word[i] - 'a'];
            cur->vecStr.emplace_back(word);
        }
    }

    bool search(string word)
    {
        if (word.size() == 0)
            return false;
        Trie *cur = this;
        for (int i = 0; i < word.size(); i++)
        {
            if(cur->child[word[i] - 'a'] == NULL)
                return false;
            cur = cur->child[word[i] - 'a'];
            if (cur->vecStr.size() == 0)
                return false;

            if (cur->vecStr.size() >= 10 && i != word.size() - 1)
                continue;
            else
            {
                for (int j = 0; j < cur->vecStr.size(); j++)
                {
                    if (cur->vecStr[j] == word)
                        return true;
                }
                return false;
            }
        }
        return false;
    }

    bool startsWith(string prefix)
    {
        if (prefix.size() == 0)
            return false;
        Trie *cur = this;
        for (int i = 0; i < prefix.size(); i++)
        {
            if(cur->child[prefix[i] - 'a'] == NULL)
                return false;
            cur = cur->child[prefix[i] - 'a'];
            if (cur->vecStr.size() == 0)
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */