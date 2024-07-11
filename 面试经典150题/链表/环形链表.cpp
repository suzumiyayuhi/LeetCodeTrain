class Solution {
public:
/*
    bool hasCycle(ListNode *head) {
        for(int  i = 0; i < 10001; i++)
        {
            if(head == NULL)
                return false;
            head = head->next;

        }
        return true;
    }
*/
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        do
        {
            if(fast == NULL)
                return false;
            int speed = 2;
            for(int i = 0; i < speed; i++)
            {
                fast = fast->next;
                if(fast == NULL)
                    return false;
            }
            slow = slow->next;
            if(fast == slow)
                return true;
        }while(fast != NULL);
        return false;
    }
};