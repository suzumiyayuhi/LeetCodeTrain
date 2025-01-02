/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        queue<TreeNode*> qq;
        vector<TreeNode*> vec;
        qq.push(root);
        while(!qq.empty())
        {
            TreeNode* tem = qq.front();
            qq.pop();
            if(tem->val == head->val)
                vec.emplace_back(tem);

            if(tem->left)
                qq.push(tem->left);
            if(tem->right)
                qq.push(tem->right);
        }

        for(int i = 0; i < vec.size(); i++)
        {
            ListNode* temListNode = head;
            queue<TreeNode*> qqq1, qqq2;
            qqq1.push(vec[i]);
            do
            {
                while(!qqq1.empty())
                {
                    TreeNode* tem = qqq1.front();
                    qqq1.pop();
                    if(tem == NULL)
                        continue;
                    if(tem->val == temListNode->val)
                    {
                        qqq2.push(tem->left);
                        qqq2.push(tem->right);
                    }
                }
                temListNode = temListNode->next;
                if(temListNode == NULL && !qqq2.empty())
                    return true;
                swap(qqq1, qqq2);
            }while(!qqq1.empty());

        }
        return false;
    }
    */
    ListNode* oriHead;
    bool isSubPath(ListNode* head, TreeNode* root)
    {
        oriHead = head;
        return dfs(head, root);
    }

    bool dfs(ListNode* head, TreeNode* root)
    {
        if(head == NULL)
            return true;
        if(root == NULL )
            return false;
/*
        bool b1 = dfs(head->next, root->left);
        bool b2 = dfs(head->next, root->right);
        bool b3 = dfs(head, root->left);
        bool b4 = dfs(head, root->right);
        return (root->val == head->val && (b1 || b2)) || 
                (head == oriHead && (b3 || b4));
*/
        return (root->val == head->val && (dfs(head->next, root->left) || dfs(head->next, root->right))) || 
                (head == oriHead && (dfs(head, root->left) || dfs(head, root->right)));
        
    }
};