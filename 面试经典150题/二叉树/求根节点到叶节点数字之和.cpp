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
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
            return 0;

        return subNum(root, 0);

    }
    int subNum(TreeNode *root, int curNum)
    {
        curNum *= 10;
        curNum += root->val;
        int sum = 0;
        if(root->left)
            sum += subNum(root->left, curNum);
        if(root->right)
            sum += subNum(root->right, curNum);
        if(root->left == NULL && root->right ==NULL)
            return curNum;
        
        return sum;
    }
};