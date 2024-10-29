#include <vector>
#include <queue>
#include <string>
using namespace std;

struct TrieNode
{
    vector<TrieNode *> children;
    ~TrieNode()
    {
        for (auto c : children)
            delete c;
    }
};

class WordDictionary
{
public:
    TrieNode *root;
    WordDictionary()
    {
        root = new TrieNode;
        root->children = vector<TrieNode *>(27, NULL);
    }

    ~WordDictionary()
    {
        delete root;
    }

    void addWord(string word)
    {
        TrieNode *cur = root;
        for (int i = 0; i < word.size(); i++)
        {
            int temI = word[i] - 'a';
            if (cur->children[temI] == NULL)
            {
                cur->children[temI] = new TrieNode;
                cur->children[temI]->children = vector<TrieNode *>(27, NULL);
            }
            cur = cur->children[temI];
        }
        if (cur->children[26] == NULL)
            cur->children[26] = new TrieNode;
    }

    bool search(string word)
    {
        queue<TrieNode *> q;
        q.push(root);
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == '.')
                subSearch(q, 30);
            else
                subSearch(q, word[i] - 'a');
            if (q.empty())
                return false;
        }
        subSearch(q, 26);
        if (!q.empty())
            return true;
        return false;
    }

    void subSearch(queue<TrieNode *> &q, int searchNum)
    {
        queue<TrieNode *> nextQ;
        while (!q.empty())
        {
            TrieNode *cur = q.front();
            q.pop();
            if (searchNum == 30)
            {
                for (int j = 0; j < 26; j++)
                {
                    if (cur->children[j])
                        nextQ.push(cur->children[j]);
                }
            }
            else
            {
                if (cur->children[searchNum])
                    nextQ.push(cur->children[searchNum]);
            }
        }
        q = nextQ;
    }
};
