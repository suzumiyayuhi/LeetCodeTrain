struct TrieNode {
    string word;
    unordered_map<char, TrieNode *> children;
    TrieNode() {
        this->word = "";
    }   
};

void insertTrie(TrieNode * root, const string & word) {
    TrieNode * node = root;

    for (auto c : word) {
        if (!node->children.count(c)) {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }

    node->word = word;
}

class Solution {
public:
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<string> ans;

    bool dfs(vector<vector<char>>& board, int x, int y, TrieNode * root) {
        char ch = board[x][y];   
     
        if (root == nullptr || !root->children.count(ch)) {
            return false;
        }

        TrieNode * nxt = root->children[ch];
        if (nxt->word.size() > 0) {
            ans.push_back(nxt->word);
            nxt->word = "";
        }
        if (!nxt->children.empty()) {
            board[x][y] = '#';
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
                    if (board[nx][ny] != '#') {
                        dfs(board, nx, ny, nxt);
                    }
                }
            }
            board[x][y] = ch;
        }
        if (nxt->children.empty()) {
            root->children.erase(ch);
        }

        return true;      
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        TrieNode * root = new TrieNode();

        insertTrie(root,word);
        for (int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[0].size(); ++j) {
                dfs(board, i, j, root);
            }
        }
        if(ans.empty())
            return false;
        return true;        
    }
};


