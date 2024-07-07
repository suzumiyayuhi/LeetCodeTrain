#include <iostream>
#include <stack>
using namespace std;
/*
struct node
{
    node()
    {
    }

    node(int val_, node *next_) : val(val_), next(next_)
    {
    }
    int val;
    node *next;
};

class MinStack
{

private:
    node *start1;
    node *start2;

public:
    MinStack()
    {
        start1 = NULL;
        start2 = new node(0x7fffffff, NULL);
    }

    void push(int val)
    {
        start1 = new node(val, start1);
        start2 = new node(val < start2->val ? val : start2->val, start2);
    }

    void pop()
    {
        if (start1 != NULL && start2 != NULL)
        {

            node *tem = start1;
            start1 = start1->next;
            delete tem;

            tem = start2;
            start2 = start2->next;
            delete tem;
        }
    }

    int top()
    {
        return start1->val;
    }

    int getMin()
    {
        return start2->val;
    }
};
*/

class MinStack {
private:
    stack<int> sss;
    stack<int> sss1;
    int curInd = 0;
public:
    MinStack() {
        sss1.push(0x7fffffff);
    }
    
    void push(int val) {
        sss.push(val);
        int tem = val < sss1.top()? val : sss1.top();
        sss1.push(tem);
    }
    
    void pop() {
        sss.pop();
        sss1.pop();
    }
    
    int top() {
        return sss.top();
    }
    
    int getMin() {
        return sss1.top();
    }
};

