/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
/*
    int index = 0;
    vector<TreeNode*> vec;
    BSTIterator(TreeNode* root) {
        detect(root);
    }
    
    void detect(TreeNode *root)
    {
        if(root->left)
            detect(root->left);
        vec.emplace_back(root);
        if(root->right)
            detect(root->right);
    }

    int next() {
        return vec[index++]->val;
    }
    
    bool hasNext() {
        return index < vec.size();
    }
    */
    stack<TreeNode*> st;
    TreeNode *cur = NULL;
    BSTIterator(TreeNode* root) {
        cur = root;
    }
    

    int next() {
        while(cur)
        {
            st.push(cur);
            cur = cur->left;
        }
        
        int res = st.top()->val;
        cur = st.top()->right;
        st.pop();
        
        return res;
    }
    
    bool hasNext() {
        return !st.empty() || cur;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */