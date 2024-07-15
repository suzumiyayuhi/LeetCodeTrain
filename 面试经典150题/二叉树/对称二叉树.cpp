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
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        TreeNode *l = root->left;
        TreeNode *r = root->right;

        if(l == NULL && r == NULL)
            return true;
        if(l == NULL || r == NULL)
            return false;
        if(l->val != r->val)
            return false;

        if(!subIsSymmetric(l->left, r->right))
            return false;
        if(!subIsSymmetric(l->right, r->left))
            return false;
        
        return true;
    }

    bool subIsSymmetric(TreeNode *a, TreeNode *b)
    {
        if(a == NULL && b == NULL)
            return true;
        if(a == NULL || b == NULL)
            return false;
        if(a->val != b->val)
            return false;
            
        if(!subIsSymmetric(a->left, b->right))
            return false;
        if(!subIsSymmetric(a->right, b->left))
            return false;
        
        return true;

    }
};