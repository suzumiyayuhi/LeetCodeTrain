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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        deque<TreeNode*> dq;
        dq.emplace_back(root);
        while(!dq.empty())
        {
            dq = sub(dq, res);
        }
        return res;
    }

    deque<TreeNode*> sub(deque<TreeNode*> dq, vector<vector<int>> &res)
    {
        deque<TreeNode*> dqq;
        vector<int> temVec;
        while(!dq.empty())
        {
            TreeNode *temNode = dq.front();
            dq.pop_front();
            temVec.emplace_back(temNode->val);
            if(temNode->left)
                dqq.emplace_back(temNode->left);
            if(temNode->right)
                dqq.emplace_back(temNode->right);
        }
        res.emplace_back(temVec);
        return dqq;
    }
};