#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}

// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

Node* reverse(Node* head)
{
    if(head->next==NULL)
        return head;
    Node* p=head,*t=head->next,*h=head;
    while(p->next!=NULL)
    {
        Node* temp=t->next;
        t->next=h;
        p->next=temp;
        h=t;
        t=temp;
    }
    return h;
}

int count(Node* head)
{
    int n=0;
    while(head!=NULL)
    {
        n++;
        head=head->next;
    }
    return n;
}

/*You are required to complete this method */
bool isPalindrome(Node *head)
{
    //Your code here
    int n=count(head);
    int i=0;
    Node* temp=head;
    while(i<n/2)
    {
        i++;
        temp=temp->next;
    }
    temp=reverse(temp);
    while(temp!=NULL)
    {
        if(temp->data!=head->data)
            return false;
        temp=temp->next;
        head=head->next;
    }
    return true;
}