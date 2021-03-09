#include<bits/stdc++.h>
using namespace std;

struct Stack{
    deque<int>dq;
    
    Stack(){}
    
    void push(int val)
    {
        dq.push_front(val);
    }
    
    int pop()
    {
        if(dq.size()!=0)
        {
            int val=dq.front();
            dq.pop_front();
            return val;
        }
        return -1;
    }
};

int main()
{
    Stack *stack=new Stack();
    cout << "Implementation of Stack using Deque\nPush operation - O(1)\nPop operation - O(1)\n";
    while(1)
    {
        cout << "Choose among the following\n1) Push in the Stack\n2) Pop from the Stack\nAny other key to Exit\n";
        int choice;
        cin >> choice;
        if(choice==1)
        {
            int val;
            cout << "Enter the value\n";
            cin >> val;
            stack->push(val);
        }
        else if(choice==2)
        {
            int val=stack->pop();
            if(val==-1)
                cout << "Empty Stack\n";
            else
                cout << "Popped Element: " << val << '\n';
        }
        else
            break;
    }
}