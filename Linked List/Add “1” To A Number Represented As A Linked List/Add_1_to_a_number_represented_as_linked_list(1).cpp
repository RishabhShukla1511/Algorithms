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

string getfinString(Node* head)
{
    string num="";
    while(head!=NULL)
    {
        num+=to_string(head->data);
        head=head->next;
    }
    int carry=1,n=num.size();
    for(int i=n-1;i>=0;i--)
    {
        int val=int(num[i]-'0')+carry;
        num[i]=char(val%10+48);
        carry=val/10;
    }
    if(carry!=0)
        return to_string(carry)+num;
    return num;
}

Node* addOne(Node *head) 
{
    // Your Code here
    // return head of list after adding one
    string num=getfinString(head);
    Node* temp=head,*prev=head;
    int pos=0;
    while(temp!=NULL)
    {
        temp->data=int(num[pos++]-'0');
        prev=temp;
        temp=temp->next;
    }
    if(pos!=num.size())
        prev->next=new Node(int(num[pos]-'0'));
    return head;
}