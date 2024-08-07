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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode *head = new ListNode();
        ListNode *tem = head;
        while(l1 != NULL || l2 != NULL)
        {
            if(l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            tem->val = sum % 10;
            int temSum = sum / 10;
            if(l1 != NULL || l2 != NULL)
            {
                ListNode *temm = new ListNode();
                tem->next = temm;
                tem = tem->next;
            }
            else if(temSum)
            {
                ListNode *temm = new ListNode(temSum);
                tem->next = temm;
                tem = tem->next;
            }
            
            sum = temSum;
        }
        return head;
    }
};