#include <iostream>
#include <string>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode *reverseLeft = fakeHead;
        while (reverseLeft != NULL)
        {
            ListNode *temNode = reverseLeft;
            for (int count = 0; count < k; count++)
            {
                if (temNode->next == NULL)
                {
                    auto res = fakeHead->next;
                    delete fakeHead;
                    return res;
                }
                temNode = temNode->next;
            }

            ListNode *curNode = reverseLeft->next;
            for (int count = 1; count < k; count++)
            {
                ListNode *rightNode = curNode->next;
                curNode->next = rightNode->next;
                rightNode->next = reverseLeft->next;
                reverseLeft->next = rightNode;
            }
            reverseLeft = curNode;
        }
        auto res = fakeHead->next;
        delete fakeHead;
        return res;
    }
};

int main()
{
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n5->next = n5;
    Solution sol;
    sol.reverseKGroup(n1, 2);
    return 0;
}