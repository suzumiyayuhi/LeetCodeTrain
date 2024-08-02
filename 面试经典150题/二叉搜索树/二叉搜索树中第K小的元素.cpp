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
    int kthSmallest(TreeNode* root, int k) {
        int time = 0;
        int res;
        sub(root, k, time, res);
        return res;
    }

    void sub(TreeNode *root, int k, int &time, int &res)
    {
        if(root->left && time < k)
            sub(root->left, k, time, res);
        time++;
        if(time == k)
            res = root->val;
        if(root->right && time < k)
            sub(root->right, k, time, res);
    }
};