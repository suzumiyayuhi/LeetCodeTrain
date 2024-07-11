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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        ListNode *head;
        if(list1->val < list2->val)
        {
            head = list1;
            list1 = list1->next;
        }
        else
        {
            head = list2;
            list2 = list2->next;
        }
        ListNode *tem = head;
        while(list1 || list2)
        {
            if(list1 == NULL)
            {
                tem->next = list2;
                return head;
            }
            else if(list2 == NULL)
            {
                tem->next = list1;
                return head;
            }
                
            ListNode *temm;    
            if(list1->val < list2->val)
            {
                temm = list1;
                list1 = list1->next;
                tem->next = temm;
                tem = tem->next;
            }
            else
            {
                temm = list2;
                list2 = list2->next;
                tem->next = temm;
                tem = tem->next;
            }
        }
        return head;
    }
};