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
    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        vector<int> vec;
        sub(root, vec);  
        for(int i = 0; i < vec.size() - 1; i++)
            res = min(res, abs(vec[i] - vec[i + 1]));
        return res;
    }

    void sub(TreeNode *root, vector<int> &vec)
    {
        if(root->left)
            sub(root->left, vec);
        vec.emplace_back(root->val);
        if(root->right)
            sub(root->right, vec);
    }
};