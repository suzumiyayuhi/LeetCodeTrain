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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        vector<ListNode*> vec;
        ListNode *tem = head;
        while(tem)
        {
            vec.emplace_back(tem);
            tem = tem->next;
        }
        int n = vec.size();
        k %= n;
        if(k)
        {
            vec[n - k - 1]->next = vec[n - 1]->next; 
            vec[n - 1]->next = head;
            head = vec[n - k];
        }
        return head;
    }
};