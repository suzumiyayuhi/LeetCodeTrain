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
    int maxPathSum(TreeNode* root) {
        int ss = -10001;
        int xx = subMax(root, ss);
        return max(ss, xx);
    }

    int subMax(TreeNode* root, int &lrm)
    {
        int a = -10001, b = -10001;
        if(root->left)
            a = subMax(root->left, lrm);
        if(root->right)
            b = subMax(root->right, lrm);
        int c = max(a, b);
        
        int rt = max(root->val, root->val + c);
        lrm = max(a + b + root->val, lrm);
        lrm = max(lrm , c);
        return rt;
    }


};