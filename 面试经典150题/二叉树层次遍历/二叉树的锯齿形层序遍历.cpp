#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        deque<TreeNode*> dq;
        dq.emplace_back(root);
        bool flag = true;
        while(!dq.empty())
        {
            dq = sub(dq, res, flag);
        }
        return res;
    }

    deque<TreeNode*> sub(deque<TreeNode*> dq, vector<vector<int>> &res, bool &flag)
    {
        vector<int> tem;
        deque<TreeNode*> dqq;
        if(flag)
        {
            while(!dq.empty())
            {
                TreeNode *temNode = dq.front();
                dq.pop_front();
                tem.emplace_back(temNode->val);
                if(temNode->left)
                    dqq.emplace_back(temNode->left);
                if(temNode->right)
                    dqq.emplace_back(temNode->right);
            }
         }
         else
         {
            while(!dq.empty())
            {
                TreeNode *temNode = dq.back();
                dq.pop_back();
                tem.emplace_back(temNode->val);
                if(temNode->right)
                    dqq.emplace_front(temNode->right);
                if(temNode->left)
                    dqq.emplace_front(temNode->left);

            }
         }
        res.emplace_back(tem);
        flag = !flag;
        return dqq;
    }
};

int main()
{
}