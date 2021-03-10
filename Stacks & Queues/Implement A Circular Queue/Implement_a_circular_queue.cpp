#include<bits/stdc++.h>
using namespace std;

struct CircularQueue{
    int *arr,front,rear,qsize,cqsize;
    
    CircularQueue(int n);

    void enQueue();
    void deQueue();
    void getFront();
    void getRear();
    bool isEmpty();
    bool isFull();
    int getSize();
};

CircularQueue::CircularQueue(int n)
{
    arr=new int[n];
    front=rear=qsize=0;
    cqsize=n;
}

void CircularQueue::enQueue()
{
    if(isFull())
        cout << "Queue Overflow\n";
    else
    {
        cout << "Enter the value to enqueue\n";
        int val;
        cin >> val;
        arr[rear++]=val;
        qsize++;
    }
    return;
}

void CircularQueue::deQueue()
{
    if(isEmpty())
        cout << "Empty Circular Queue\n";
    else
    {
        cout << "Popped element: " << arr[front++] << '\n';
        qsize--;
    }
    return;
}

void CircularQueue::getFront()
{
    if(isEmpty())
        cout << "Empty Circular Queue\n";
    else
        cout << "Front element: " << arr[front] << '\n';
    return;
}

void CircularQueue::getRear()
{
    if(isEmpty())
        cout << "Empty Circular Queue\n";
    else
        cout << "Rear element: " << arr[rear-1] << '\n';
    return;
}

bool CircularQueue::isEmpty()
{
    return qsize==0;   
}

bool CircularQueue::isFull()
{
    return qsize==cqsize;   
}

int CircularQueue::getSize()
{
    return qsize;    
}

void userDrivenImplementation()
{
    cout << "Enter the size of the CircularQueue\n";
    int n;
    cin >> n;
    CircularQueue *cq=new CircularQueue(n);
    while(1)
    {
        cout << "Enter your choice\n1) Enqueue\n2) Dequeue\n3) Front Element\n4) Rear Element\n5) isEmpty\n6) isFull\n7) Size\n -1 to exit\n";
        int choice;
        cin >> choice;
        if(choice==1)
            cq->enQueue();
        else if(choice==2)
            cq->deQueue();
        else if(choice==3)
            cq->getFront();
        else if(choice==4)
            cq->getRear();
        else if(choice==5)
        {
            if(cq->isEmpty())
                cout << "Empty Circular Queue\n";
            else
                cout << "Not Empty Circular Queue\n";
        }
        else if(choice==6)
        {
            if(cq->isFull())
                cout << "Full Circular Queue\n";
            else
                cout << "Not Full Circular Queue\n";
        }
        else if(choice==7)
            cout << "The size of the queue is: " << cq->getSize() << '\n';
        else
            break;
    }
    return;
}

int main()
{
    cout << "Implementation of Circular Queue\n";
    userDrivenImplementation();
    return 0;    
}