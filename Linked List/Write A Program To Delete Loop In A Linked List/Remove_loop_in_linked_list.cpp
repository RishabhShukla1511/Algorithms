// driver code

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

void removeLoop(Node* head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}
// } Driver Code Ends


/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

Node* detectLoop(Node* head)
{
    // your code here
    Node* hare=head,*tort=head;
    while(tort!=NULL)
    {
        if(tort->next==NULL)   
            break;
        tort=tort->next->next;
        hare=hare->next;
        if(tort==hare)
            return tort;
    }
    return NULL;
}

void removeLoop(Node* head)
{
    // code here
    // just remove the loop without losing any nodes
    Node* t=detectLoop(head),*h=t;
    if(t!=NULL)
    {
        int s=1;
        h=h->next;
        while(h!=t)
        {
            s++;
            h=h->next;
        }
        h=head,t=h;
        while(s--)
            t=t->next;
        while(t!=h)
        {
            t=t->next;
            h=h->next;
        }
        while(t->next!=h)
            t=t->next;
        t->next=NULL;
    }
}