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
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode *hair = new ListNode(0);
        hair->next = head;
        ListNode *leftNode = hair;
        ListNode *temNode = leftNode->next;
        while(temNode)
        {
            if(temNode->next == nullptr)
                break;
            if(temNode->val == temNode->next->val)
            {
                do
                {
                    ListNode *temm = temNode->next;
                    temNode->next = temm->next;
                    delete temm;
                    if(temNode->next == nullptr)
                        break;
                }while(temNode->next->val == temNode->val);
                ListNode *st = leftNode->next;
                leftNode->next = st->next;
                temNode = leftNode->next;
                delete st;
            }
            else
            {
                leftNode = leftNode->next;
                temNode = leftNode->next;
            }
            
                
        }
        return hair->next;
    }
};