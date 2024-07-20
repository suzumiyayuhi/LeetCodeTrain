/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
            return false;

        if (subPath(root, targetSum, root->val))
            return true;
        return false;
    }
    bool subPath(TreeNode *root, int targetSum, int curSum)
    {
        bool flag1 = false, flag2 = false;
        if (root->left)
            flag1 = subPath(root->left, targetSum, curSum + root->left->val);
        if (root->right)
            flag2 = subPath(root->right, targetSum, curSum + root->right->val);
        if (root->left == NULL && root->right == NULL)
            return curSum == targetSum;
        else
            return flag1 || flag2;
    }
};