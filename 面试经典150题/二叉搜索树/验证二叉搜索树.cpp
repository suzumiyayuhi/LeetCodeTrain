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
    bool isValidBST(TreeNode* root) {
        vector<int> vec;
        sub(root, vec);
        for(int i = 0; i < vec.size() - 1; i++)
        {
            if(vec[i] >= vec[i + 1])
                return false;
        }
        return true;
    }

    void sub(TreeNode *root, vector<int> &vec)
    {
        if(root->left)
            sub(root->left, vec);
        vec.emplace_back(root->val);
        if(root->right)
            sub(root->right, vec);

    }
    */

    bool isValidBST(TreeNode* root) {
        vector<int> vec;
        int lastNum = INT_MIN;
        bool first = true;
        return sub(root, lastNum, first);
    }

    bool sub(TreeNode *root, int &lastNum, bool &first)
    {
        bool flag1 = true, flag2 = true;
        if(root->left)
            flag1 = sub(root->left, lastNum, first);
        if(!flag1)
            return false;

        if(first)
            first = false;
        else if(lastNum >= root->val)
            return false;
        lastNum = root->val;

        if(root->right)
            flag2 = sub(root->right, lastNum, first);
        return flag1 && flag2;
    }
};