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
class Solution
{
public:
    unordered_map<int, int> inIndex;

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for(int i = 0; i != inorder.size(); i++)
            inIndex[inorder[i]] = i; 

        return subBuildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* subBuildTree(vector<int> &preorder, vector<int> &inorder, int preLeft, int preRight, int inLeft, int inRight)
    {
        if(preLeft > preRight)
            return NULL;
        int inMid = inIndex[preorder[preLeft]];
        TreeNode *root = new TreeNode(preorder[preLeft]);
        int leftCount = inMid - inLeft;
    
        root->left = subBuildTree(preorder, inorder, preLeft + 1, preLeft + leftCount, inLeft, inRight - leftCount);
        root->right = subBuildTree(preorder, inorder, preLeft + leftCount + 1, preRight, inMid + 1, inRight);
        return root;
    }
};