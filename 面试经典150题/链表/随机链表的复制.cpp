class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        if(head == NULL)
            return NULL;

        for(Node *temNode = head; temNode != NULL; temNode = temNode->next->next)
        {
            Node *temNode2 = new Node(temNode->val);
            temNode2->next = temNode->next;
            temNode->next = temNode2;
        }

        for(Node *temNode = head; temNode != NULL; temNode = temNode->next->next)
        {
            Node *temNode2 = temNode->next;
            temNode2->random = temNode->random == NULL ? NULL : temNode->random->next;
        }

        Node *resHead = head->next;
        for(Node *temNode = head; temNode != NULL; temNode = temNode->next)
        {
            Node *temNode2 = temNode->next;
            temNode->next = temNode2->next;
            temNode2->next = temNode->next == NULL ? NULL : temNode->next->next;
        }
        return resHead;
    }
};