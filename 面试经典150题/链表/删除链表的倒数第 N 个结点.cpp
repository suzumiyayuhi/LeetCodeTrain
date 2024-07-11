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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> vec;
        ListNode *tem = head;
        while(tem)
        {
            vec.emplace_back(tem);
            tem = tem->next;
        }
        int sz = vec.size();
        if(sz - n == 0)
            head = head->next;
        else
            vec[sz - n - 1]->next = vec[sz - n]->next;
        delete vec[sz - n];
        return head;
    }
};