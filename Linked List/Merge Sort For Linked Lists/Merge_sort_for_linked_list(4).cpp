#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends


/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


void create(Node **head,int val)
{
    Node *newNode=new Node(val);
    if(*head==NULL)
        *head=newNode;
    else
    {
        Node *ptr=*head;
        while(ptr->next)
            ptr=ptr->next;
        ptr->next=newNode;   
    }    
}

void merge(Node **head,int l,int mid,int h)
{
    int n=mid-l+1,m=h-mid,k=0,i=0,j=0;
    Node *a=NULL,*b=NULL,*curr=*head;
    while(k<l)
    {
        curr=curr->next;
        k++;
    }
    for(i=l;i<=mid;i++)
    {
        create(&a,curr->data);
        curr=curr->next;
    }
    for(i=mid+1;i<=h;i++)
    {
        create(&b,curr->data);
        curr=curr->next;
    }
    i=0,j=0,k=0;
    Node *temp=*head;
    while(k<l)
    {
        temp=temp->next;
        k++;
    }
    while(i<n && j<m)
    {
        if(a->data<b->data)
        {
            i++;
            temp->data=a->data;
            a=a->next;
        }
        else
        {
            j++;
            temp->data=b->data;
            b=b->next;
        }
        temp=temp->next;
    }
    while(i<n)
    {
        i++;
        temp->data=a->data;
        a=a->next;
        temp=temp->next;
    }
    while(j<m)
    {
        j++;
        temp->data=b->data;
        b=b->next;
        temp=temp->next;
    }
}

Node* mergeSort(Node **head,int l,int h)
{
    if(l<h)
    {
        int mid=l+(h-l)/2;
        mergeSort(head,l,mid);
        mergeSort(head,mid+1,h);
        merge(head,l,mid,h);
    }
    return *head;
}

int count(Node *head)
{
    int n=0;
    while(head)
    {
        n++;
        head=head->next;
    }
    return n;
}

/* Function to mergesort the linked list
   It should return head of the modified list  */
Node* mergeSort(Node* head) {
    // your code here
    int n=count(head);
    return mergeSort(&head,0,n-1);
}


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends