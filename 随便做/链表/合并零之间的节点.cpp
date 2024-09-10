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
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *right = head->next;
        ListNode *res = new ListNode(), *resNext = res, *resPrev;
        while(right)
        {
            if(right->val == 0)
            {
                right = right->next;
                resNext->next = new ListNode();
                resPrev = resNext;
                resNext = resNext->next;
            }
            else
            {
                resNext->val += right->val;
                right = right->next;
            }
        }
        resPrev->next = NULL;
        delete resNext;
        return res;
    }
};