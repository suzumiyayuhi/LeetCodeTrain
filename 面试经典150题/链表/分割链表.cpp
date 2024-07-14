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
    ListNode *partition(ListNode *head, int x)
    {
        if (head == NULL)
            return NULL;
        ListNode *hair = new ListNode(-1, head);
        ListNode *fast = hair;
        ListNode *slow = fast;
        while (fast->next)
        {
            if (fast->next->val < x)
            {
                if(slow == fast)
                {
                    fast = fast->next;
                    slow = slow->next;
                    continue;
                }
                    
                ListNode *temNode = fast->next;
                fast->next = temNode->next;

                temNode->next = slow->next;
                slow->next = temNode;
                slow = slow->next;
            }
            else
            {
                fast = fast->next;
            }
        }
        auto res = hair->next;
        delete hair;
        return res;
    }
    
};