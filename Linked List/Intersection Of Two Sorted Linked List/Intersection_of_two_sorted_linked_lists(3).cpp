//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
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
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}
// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    unordered_map<int,int>m;
    while(head1!=NULL)
    {
        m[head1->data]++;
        head1=head1->next;
    }
    vector<int>v;
    while(head2!=NULL)
    {
        if(m[head2->data])
        {
            v.push_back(head2->data);
            m[head2->data]--;
        }
        head2=head2->next;
    }
    if(v.size()!=0)
    {
        Node* head=new Node(v[0]);
        Node* temp=head;
        for(int i=1;i<v.size();i++)
        {
            head->next=new Node(v[i]);
            head=head->next;
        }
        return temp;
    }
    return NULL;
}