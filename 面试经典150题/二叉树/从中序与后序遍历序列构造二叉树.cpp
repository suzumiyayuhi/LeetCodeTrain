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
    unordered_map<int, int> inIndex;

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        for(int i = 0; i != inorder.size(); i++)
            inIndex[inorder[i]] = i; 
        int n = inorder.size() - 1;
        int m = postorder.size() - 1;
        return subBuildTree(inorder, postorder, 0, n, 0, m);
    }

    TreeNode *subBuildTree(vector<int> &inorder, vector<int> &postorder, int inLeft, int inRight, int postLeft, int postRight)
    {
        if(postLeft > postRight)
            return NULL;
        TreeNode *root = new TreeNode(postorder[postRight]);
        int inMid = inIndex[postorder[postRight]];
        int leftCount = inMid - inLeft;

        root->left = subBuildTree(inorder, postorder, inLeft, inMid - 1, postLeft, postLeft + leftCount - 1);
        root->right = subBuildTree(inorder, postorder, inMid + 1, inRight, postLeft + leftCount, postRight - 1);

        return root;
    }
};