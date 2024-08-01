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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        if (root == NULL)
            return res;
        deque<TreeNode *> dq;
        dq.emplace_back(root);
        while(!dq.empty())
        {
            res.emplace_back(dq.back()->val);
            dq = sub(dq);
        }
        return res;
    }

    deque<TreeNode*> sub(deque<TreeNode*> dq)
    {
        deque<TreeNode *> subDq;
        while(!dq.empty())
        {
            TreeNode *cur = dq.front();
            dq.pop_front();
            if(cur->left)
                subDq.emplace_back(cur->left);
            if(cur->right)
                subDq.emplace_back(cur->right);
        }
        return subDq;
    }


};