// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

struct Node* addTwoLists(struct Node* first, struct Node* second);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends


/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

void reverse(struct Node** node)
{
    struct Node* current=*node;
    struct Node* next=NULL;
    struct Node* prev=NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    *node=prev;
}


struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    reverse(&first);
    reverse(&second);
    struct Node* ans=NULL,*current=NULL,*f=first,*s=second;
    int carry=0;
    while(f!=NULL && s!=NULL)
    {
        int sum=f->data+s->data+carry;
        struct Node* newnode;
        if(sum/10!=0)
        {
            newnode=new Node(sum%10);
            carry=sum/10;
        }
        else
        {
            newnode=new Node(sum);
            carry=0;
        }
        if(ans==NULL)
        {
            ans=newnode;
            current=ans;
        }
        else
        {
            current->next=newnode;
            current=newnode;
        }
        f=f->next;
        s=s->next;
    }
    while(f!=NULL)
    {
        int sum=f->data+carry;
        struct Node* newnode;
        if(sum/10!=0)
        {
            newnode=new Node(sum%10);
            carry=sum/10;
        }
        else
        {
            newnode=new Node(sum);
            carry=0;
        }
        if(ans==NULL)
        {
            ans=newnode;
            current=ans;
        }
        else
        {
            current->next=newnode;
            current=newnode;
        }   
        f=f->next;
    }
    while(s!=NULL)
    {
        int sum=s->data+carry;
        struct Node* newnode;
        if(sum/10!=0)
        {
            newnode=new Node(sum%10);
            carry=sum/10;
        }
        else
        {
            newnode=new Node(sum);
            carry=0;
        }
        if(ans==NULL)
        {
            ans=newnode;
            current=ans;
        }
        else
        {
            current->next=newnode;
            current=newnode;
        }   
        s=s->next;
    }
    if(carry!=0)
    {
        struct Node* newnode=new Node(carry);
        current->next=newnode;
    }
    reverse(&ans);
    return ans;
}