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
/*
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL)
            return NULL;
        ListNode *curNode = head;
        int count = 1;
        ListNode *leftNode = NULL;
        while(left > count)
        {
            count++;
            leftNode = curNode;
            curNode = curNode->next;
        }
        ListNode *reverseHead = curNode;
        ListNode *reverseLeft = leftNode;
        while(right > count)
        {
            count++;
            ListNode *rightNode = curNode->next;
            curNode->next = leftNode;
            leftNode = curNode;
            curNode = rightNode;
        }
        ListNode *rightNode = curNode == NULL? NULL : curNode->next;
        curNode->next = leftNode;
        reverseHead->next = rightNode;
        if(reverseLeft != NULL)
            reverseLeft->next = curNode;
        if(left == 1)
            return curNode;
        else
            return head;
    }
    */

    /*
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        ListNode *fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode *reverseLeft = fakeHead;
        int count = 1;
        while(left > count)
        {
            count++;
            reverseLeft = reverseLeft->next;
        }
        
        ListNode *curNode = reverseLeft->next;
        while(right > count)
        {
            count++;
            ListNode *rightNode = curNode->next;
            curNode->next = rightNode->next;
            rightNode->next = reverseLeft->next;
            reverseLeft->next = rightNode;
        }
        auto res = fakeHead->next;
        delete fakeHead;
        return res;
    }
    */

    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        ListNode *fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode *reverseLeft = fakeHead;
        for(int i = 1; i < left; i++)
        {
            reverseLeft = reverseLeft->next;
        }
        
        ListNode *curNode = reverseLeft->next;
        for(int i = left; i < right; i++)
        {
            ListNode *rightNode = curNode->next;
            curNode->next = rightNode->next;
            rightNode->next = reverseLeft->next;
            reverseLeft->next = rightNode;
        }
        auto res = fakeHead->next;
        delete fakeHead;
        return res;
    }
};