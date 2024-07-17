#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *process(Node *parentNode, Node *firstChild)
    {
        Node *tem = parentNode;
        Node *temChild = firstChild;
        if (temChild == tem->left && tem->right != NULL)
        {
            temChild->next = tem->right;
            temChild = temChild->next;
        }
        tem = tem->next;
        while (tem)
        {
            if (tem->left)
            {
                temChild->next = tem->left;
                temChild = temChild->next;
            }
            if(tem->right)
            {
                temChild->next = tem->right;
                temChild = temChild->next;
            }
            tem = tem->next;
        }
        temChild->next = NULL;

        return firstChild;
    }

    Node *connect(Node *root)
    {
        if (root == NULL)
            return root;
        root->next = NULL;

        Node *curNode = root;

        while (curNode)
        {
            if (curNode->left)
                curNode = process(curNode, curNode->left);
            else if (curNode->right)
                curNode = process(curNode, curNode->right);
            else
                curNode = curNode->next;
        }
        return root;
    }
};