/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *res = NULL;
        sub(root, p, q, res);
        return res;
    }

    bool sub(TreeNode *root, TreeNode* p, TreeNode* q, TreeNode *&res)
    {
        bool flag1 = false, flag2 = false;
        if(root->left && res == NULL)
            flag1 = sub(root->left, p, q, res);
        if(root->right && res == NULL)
            flag2 = sub(root->right, p, q, res);
        if(flag1 && flag2 && res == NULL)
            res = root;
        if(root == p || root == q)
        {
            if(flag1 || flag2)
                res = root;
            return true;
        }
        else
            return flag1 || flag2;
    }
};