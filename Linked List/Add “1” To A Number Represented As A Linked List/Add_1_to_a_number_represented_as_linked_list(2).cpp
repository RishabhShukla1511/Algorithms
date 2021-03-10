//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 

Node* addOne(Node *head);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        
        head = addOne(head);
        printList(head); 
    }
    return 0; 
} 
// } Driver Code Ends


//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

Node* reverse(Node* head)
{
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

Node* addOne(Node *head) 
{
    // Your Code here
    // return head of list after adding one
    if(head->next!=NULL)
        head=reverse(head);
    Node* temp=head,*prev;
    int carry=0;
    int val=temp->data+1;
    temp->data=val%10;
    carry=val/10;
    prev=temp;
    temp=temp->next;
    while(temp!=NULL)
    {
        int val=temp->data+carry;
        temp->data=val%10;
        carry=val/10;
        prev=temp;
        temp=temp->next;
    }
    if(carry!=0)
        prev->next=new Node(carry);
    if(head->next!=NULL)
        head=reverse(head);
    return head;
}