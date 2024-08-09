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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        deque<TreeNode*> dq;
        dq.emplace_back(root);
        while(!dq.empty())
        {
            
            bool flag;
            dq = sub2(dq, subRoot, flag);
            if(flag)
                return true;
        }
        return false;
    }

    deque<TreeNode*> sub2(deque<TreeNode*> dq, TreeNode *subRoot, bool &res)
    {
        deque<TreeNode*> dqq;
        while(!dq.empty())
        {
            TreeNode *temNode = dq.front();
            dq.pop_front();

            if(temNode->left)
                dqq.emplace_back(temNode->left);
            if(temNode->right)
                dqq.emplace_back(temNode->right);
            res = sub(temNode, subRoot);
            if(res)
                return dqq;
        }
        return dqq;

    }

    bool sub(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        if(p == NULL || q == NULL)
            return false;
        
        if(p->val != q->val)
            return false;
        if(!sub(p->left, q->left))
            return false;
        
        if(!sub(p->right, q->right))
            return false;
        
        return true;
    }

};