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
/*
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int a = 1, b = 1;
        if(root->left)
            a = calDepth(root->left, 1);
        if(root->right)
            b = calDepth(root->right, 1);
        return max(a,b);
    }
    int calDepth(TreeNode *node, int count)
    {
        count++;
        int a = count, b = count;
        if(node->left)
            a = calDepth(node->left, count);
        if(node->right)
            b = calDepth(node->right, count);
        return max(a,b);
    }
    */
    int maxDepth(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};