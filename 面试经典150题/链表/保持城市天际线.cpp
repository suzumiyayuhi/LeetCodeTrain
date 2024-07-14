#include <iostream>
#include <unordered_map>
using namespace std;

struct lisNode
{
    lisNode *prev;
    lisNode *next;
    int val;
    int key;
    lisNode(int val, int key)
    {
        this->val = val;
        this->key = key;
    }
};

class LRUCache
{
private:
    lisNode *hair;
    unordered_map<int, lisNode *> hs;
    int i_capacity;
    int i_count = 0;

    void moveToHead(lisNode *curNode)
    {
        if (curNode == hair || curNode->prev == hair)
            return;
        else
        {
            lisNode *leftNode = curNode->prev;
            lisNode *rightNode = curNode->next;
            leftNode->next = rightNode;
            rightNode->prev = leftNode;
            insertNodeToHead(curNode);
        }
    }

    void insertNodeToHead(lisNode *curNode)
    {
        lisNode *temNode = hair->next;
        if (temNode == NULL)
        {
            hair->next = curNode;
            hair->prev = curNode;
            curNode->next = hair;
            curNode->prev = hair;
        }
        else
        {
            curNode->next = hair->next;
            curNode->prev = hair;
            hair->next = curNode;
            temNode->prev = curNode;
        }
    }

    void removeNode(lisNode *curNode)
    {
        if (curNode == hair)
            return;
        if (curNode->next == curNode->prev)
        {
            hair->next = NULL;
            hair->prev = NULL;
            delete curNode;
        }
        else
        {
            lisNode *leftNode = curNode->prev;
            lisNode *rightNode = curNode->next;
            leftNode->next = rightNode;
            rightNode->prev = leftNode;
            delete curNode;
        }
    }

public:
    LRUCache(int capacity)
    {
        this->i_capacity = capacity;
        lisNode *h = new lisNode(-1, -1);
        h->next = NULL;
        h->prev = NULL;
        this->hair = h;
    }

    ~LRUCache()
    {
        while(hair->next != NULL)
        {
            removeNode(hair->next);
        }
        delete hair;
    }

    int get(int key)
    {
        if (this->hs.find(key) == hs.end())
            return -1;
        else
        {
            moveToHead(hs[key]);
            return hs[key]->val;
        }
    }

    void put(int key, int value)
    {
        if (hs.find(key) != hs.end())
        {
            hs[key]->val = value;
            moveToHead(hs[key]);
            return;
        }

        if (this->i_count < this->i_capacity)
        {
            lisNode *temNode = new lisNode(value, key);
            this->hs[key] = temNode;
            insertNodeToHead(temNode);
            i_count++;
        }
        else
        {
            hs.erase(hair->prev->key);
            removeNode(hair->prev);
            lisNode *temNode = new lisNode(value, key);
            this->hs[key] = temNode;
            insertNodeToHead(temNode);
        }
    }
};

int main()
{
    LRUCache ff(2);
    ff.put(2, 1);
    ff.put(1, 1);
    ff.put(2, 3);
    ff.put(4, 1);
    cout << ff.get(1) << endl;
    cout << ff.get(2) << endl;
    return 0;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */