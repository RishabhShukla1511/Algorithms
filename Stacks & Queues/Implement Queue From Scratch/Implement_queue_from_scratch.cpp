#include<bits/stdc++.h>
#define maxsize 1000
using namespace std;

struct Queue{
    int arr[maxsize],front,rear;
    Queue()
    {
        front=0;
        rear=-1;
    }
    bool isEmpty();
    bool isFull();
    void push(int key);
    void pop();
    void peek();
};

bool Queue::isFull()
{
    return rear+1==maxsize;
}

bool Queue::isEmpty()
{
    return front==rear+1;
}

void Queue::push(int key)
{
    if(!isFull())
        arr[++rear]=key;
    else
        cout << "Queue Overflow\n";
}

void Queue::pop()
{
    if(!isEmpty())
        ++front;
    else
        cout << "Empty Queue\n";
}

void Queue::peek()
{
    if(!isEmpty())
        cout << "Element in the front of Queue is: " << arr[front] << '\n';
    else
        cout << "Empty Queue\n";
}

int main()
{
    Queue *queue=new Queue();
    cout << "Following is the Implementation of Queue using array\nMaximum size is 1000\n";
    while(1)
    {
        cout << "Choose one of the following\nEnter any other key to exit\n";
        cout << "1. Push\n2. Pop\n3. Front\n4. isEmpty\n5. isFull\n";
        string choice;
        cin >> choice;
        if(choice=="1")
        {
            int key;
            cout << "Enter the value of key\n";
            cin >> key;
            queue->push(key);
        }
        else if(choice=="2")
            queue->pop();
        else if(choice=="3")
            queue->peek();
        else if(choice=="4")
        {
            if(queue->isEmpty())
                cout << "Empty Queue\n";
            else
                cout << "Not Empty Queue\n";
        }
        else if(choice=="5")
        {
            if(queue->isFull())
                cout << "Full Queue\n";
            else
                cout << "Not Full Queue\n";
        }
        else
            break;
    }
}