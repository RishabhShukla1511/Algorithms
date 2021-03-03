#include<bits/stdc++.h>
#define maxsize 1000
using namespace std;

struct Stack{
    int arr[maxsize],top;
    Stack()
    {
        top=-1;
    }
    bool isEmpty();
    bool isFull();
    void push(int key);
    void pop();
    void peek();
};

bool Stack::isFull()
{
    return top+1==maxsize;
}

bool Stack::isEmpty()
{
    return top==-1;
}

void Stack::push(int key)
{
    if(!isFull())
        arr[++top]=key;
    else
        cout << "Stack Overflow\n";
}

void Stack::pop()
{
    if(!isEmpty())
        --top;
    else
        cout << "Empty Stack\n";
}

void Stack::peek()
{
    if(!isEmpty())
        cout << "Element at the top of Stack is: " << arr[top] << '\n';
    else
        cout << "Empty Stack\n";
}

int main()
{
    Stack *stack=new Stack();
    cout << "Following is the Implementation of Stack using array\nMaximum size is 1000\n";
    while(1)
    {
        cout << "Choose one of the following\nEnter any other key to exit\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. isFull\n";
        string choice;
        cin >> choice;
        if(choice=="1")
        {
            int key;
            cout << "Enter the value of key\n";
            cin >> key;
            stack->push(key);
        }
        else if(choice=="2")
            stack->pop();
        else if(choice=="3")
            stack->peek();
        else if(choice=="4")
        {
            if(stack->isEmpty())
                cout << "Empty Stack\n";
            else
                cout << "Not Empty Stack\n";
        }
        else if(choice=="5")
        {
            if(stack->isFull())
                cout << "Full Stack\n";
            else
                cout << "Not Full Stack\n";
        }
        else
            break;
    }
}