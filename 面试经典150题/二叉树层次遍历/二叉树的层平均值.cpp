class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        deque<TreeNode*> dq;
        dq.emplace_back(root);
        vector<double> avgs;
        while(!dq.empty())
        {
            double avg = 0;
            dq = sub(dq, avg);
            avgs.emplace_back(avg);
        }
        return avgs;
    }

    deque<TreeNode*> sub(deque<TreeNode*> dq, double &avg)
    {
        deque<TreeNode*> dqq;
        int n = dq.size();
        while(!dq.empty())
        {
            TreeNode *temNode = dq.front();
            avg += temNode->val;
            dq.pop_front();
            if(temNode->left)
                dqq.emplace_back(temNode->left);
            if(temNode->right)
                dqq.emplace_back(temNode->right);
        }
        avg /= n;
        return dqq;
    }

};