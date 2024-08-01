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
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int maxDepth = 0;
        int lastLeafNum = 0;
        int noComplete = 1;
        sub(root, 0, maxDepth, lastLeafNum, noComplete);
        if(maxDepth == 1)
            return 1;
        if(lastLeafNum)
            return (2 << (maxDepth - 2)) - 1 + lastLeafNum;
        else
            return (2 << (maxDepth - 1)) - 1 ;
    }

    void sub(TreeNode *root, int depth, int &maxDepth, int &lastLeafNum, int &noComplete)
    {
        depth++;
        maxDepth = max(maxDepth, depth);
        if(root->left && noComplete)
            sub(root->left, depth, maxDepth, lastLeafNum, noComplete);
        if(root->right && noComplete)
            sub(root->right, depth, maxDepth, lastLeafNum, noComplete);
        if(depth < maxDepth && !(root->right))
            noComplete = 0;
        if(depth == maxDepth)
            lastLeafNum++;
    }
};