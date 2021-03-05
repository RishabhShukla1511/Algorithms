#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next,*prev;
    Node(int data)
    {
        next=prev=NULL;
        this->data=data;
    }
};

struct Stack{
    Node *top,*middle;
    int size,mid;
    Stack()
    {
        top=NULL;
        middle=NULL;
        size=0;
        mid=-1;
    }
    bool isEmpty();
    void push(int key);
    void pop();
    void peek();
    void findMiddle();
    void deleteMiddle();
};

bool Stack::isEmpty()
{
    return (size==0);
}

void Stack::findMiddle()
{
    if(size==0)
        cout << "Empty Stack\n";
    else
        cout << "Element in the middle: " << middle->data << '\n';
}

void Stack::deleteMiddle()
{
    if(size==0)
    {
        cout << "Empty Stack\n";
        return;
    }
    else
    {
        Node *temp=middle;
        size--;
        temp=NULL;
    }
    if(size==1)
    {
        middle=top;
        mid=0;
    }
    else if(mid!=(size-1)/2)
    {
        mid=(size-1)/2;
        middle=middle->prev;
    }
}

void Stack::push(int key)
{
    Node *newnode=new Node(key);
    if(top==NULL)
    {
        top=newnode;
        middle=top;
        size++;
        mid=0;
        if(size==1)
            middle=top;
        return;
    }
    newnode->prev=top;
    top->next=newnode;
    top=top->next;
    size++;
    if(mid!=(size-1)/2)
    {
        mid=(size-1)/2;
        middle=middle->next;
    }
    if(size==1)
        middle=top;
}

void Stack::pop()
{
    if(size==0)
        cout << "Empty Stack\n";
    else
    {
        Node *temp=top;
        top=top->prev;
        temp=NULL;
        size--;
        if(mid!=(size-1)/2)
        {
            mid=(size-1)/2;
            middle=middle->prev;
        }
    }
}

void Stack::peek()
{
    if(!isEmpty())
        cout << "Element at the top of Stack is: " << top->data << '\n';
    else
        cout << "Empty Stack\n";
}

int main()
{
    Stack *stack=new Stack();
    cout << "Following is the Implementation of Stack using Doubly Linkedin List along with operations on middle element\n";
    while(1)
    {
        cout << "Choose one of the following\nEnter any other key to exit\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. Find Middle\n6. Delete Middle\n";
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
            stack->findMiddle();
        else if(choice=="6")
            stack->deleteMiddle();
        else
            break;
    }
}