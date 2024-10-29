#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
using namespace std;

/*
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
            if (cur->children[searchNum])
                nextQ.push(cur->children[searchNum]);
        }
        q = nextQ;
    }
};

class Solution
{
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        WordDictionary wd;
        set<string> finded;
        for (int i = 0; i < words.size(); i++)
            wd.addWord(words[i]);

        for (int row = 0; row < board.size(); row++)
        {
            for (int col = 0; col < board[0].size(); col++)
            {
                findFromWD(row, col, board, wd, finded);
            }
        }

        vector<string> res;
        for (auto iter = finded.begin(); iter != finded.end(); iter++)
        {
            res.emplace_back(*iter);
        }

        return res;
    }

    int dir[4][2] = {0, 1,
                     1, 0,
                     0, -1,
                     -1, 0};


    void findFromWD(int &row, int &col, vector<vector<char>> &board, WordDictionary &wd, set<string> &ssse)
    {
        vector<vector<int>> passed(board.size(), vector<int>(board[0].size(), 0));
        passed[row][col] = 1;
        string str;
        str += board[row][col];
        if (wd.search(str))
            ssse.insert(str);
        subFind(row, col, board, wd, passed, str, ssse);
    }

    void subFind(int &row, int &col, vector<vector<char>> &board, WordDictionary &wd, vector<vector<int>> passed, string str, set<string> &ssse)
    {
        for (int i = 0; i < 4; i++)
        {
            int temRow = row + dir[i][0];
            int temCol = col + dir[i][1];
            if (str.size() == 10)
                continue;
            if (temRow >= board.size() || temRow < 0)
                continue;
            if (temCol >= board[0].size() || temCol < 0)
                continue;
            if (passed[temRow][temCol])
                continue;

            string temStr = str;
            str += board[temRow][temCol];
            passed[temRow][temCol] = 1;

            if (wd.search(str))
                ssse.insert(str);

            subFind(temRow, temCol, board, wd, passed, str, ssse);

            passed[temRow][temCol] = 0;
            str = temStr;
        }
    }

};
*/

struct TrieNode
{
    bool isWord;
    string word;
    vector<TrieNode *> children;
    TrieNode()
    {
        isWord = false;

        children = vector<TrieNode *>(26, 0);
    }

    ~TrieNode()
    {
        for (auto c : children)
            delete c;
    }
};

void AddToTrie(TrieNode *root, string &word)
{
    TrieNode *cur = root;
    for (int i = 0; i < word.size(); i++)
    {
        int temI = word[i] - 'a';
        if (cur->children[temI] == NULL)
        {
            cur->children[temI] = new TrieNode;
            cur->children[temI]->children = vector<TrieNode *>(26, NULL);
        }
        cur = cur->children[temI];
    }
    cur->isWord = true;
    cur->word = word;
}

class Solution
{
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        TrieNode *root = new TrieNode;
        set<string> finded;
        for (int i = 0; i < words.size(); i++)
            AddToTrie(root, words[i]);

        for (int row = 0; row < board.size(); row++)
        {
            for (int col = 0; col < board[0].size(); col++)
            {
                int tem = board[row][col] - 'a';
                findFromWD(row, col, board, root->children[tem], finded);
            }
        }

        vector<string> res;
        for (auto iter = finded.begin(); iter != finded.end(); iter++)
        {
            res.emplace_back(*iter);
        }

        return res;
    }

    int dir[4][2] = {0, 1,
                     1, 0,
                     0, -1,
                     -1, 0};

    void findFromWD(int &row, int &col, vector<vector<char>> &board, TrieNode *root, set<string> &ssse)
    {

        char temC = board[row][col];
        if (root == NULL)
            return;
        if (root->isWord)
            ssse.insert(root->word);
        board[row][col] = '#';

        for (int i = 0; i < 4; i++)
        {
            int temRow = row + dir[i][0];
            int temCol = col + dir[i][1];

            if (temRow >= board.size() || temRow < 0)
                continue;
            if (temCol >= board[0].size() || temCol < 0)
                continue;
            if (board[temRow][temCol] == '#')
                continue;

            int ttt = board[temRow][temCol] - 'a';
            findFromWD(temRow, temCol, board, root->children[ttt], ssse);
        }
        board[row][col] = temC;
    }
};

int main()
{

    // vector<vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    // vector<string> words = {"oath","pea","eat","rain"};

    vector<vector<char>> board = {{'a'}};
    vector<string> words = {"a"};

    Solution sol;
    sol.findWords(board, words);
    return 0;
}