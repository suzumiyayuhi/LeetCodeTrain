#include <iostream>
#include <vector>
#include <unordered_map>
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

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;
        subFlatten(root);
    }
    TreeNode *subFlatten(TreeNode *root)
    {
        TreeNode *temLeft = root->left;
        TreeNode *temRight = root->right;
        TreeNode *last = root;
        if (temLeft)
        {
            last = subFlatten(temLeft);
            root->right = temLeft;
            last->right = temRight;
			root->left = NULL;
        }
        if (temRight)
        {
            last = subFlatten(temRight);
        }
    

        return last;
    }
};