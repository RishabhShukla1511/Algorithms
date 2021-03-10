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

void splitFrontandback(Node *head,Node **a,Node **b)
{
    Node *fast=head->next,*slow=head;
    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast)
        {
            fast=fast->next;
            slow=slow->next;   
        }
    }
    *a=head;
    *b=slow->next;
    slow->next=NULL;
}

Node* merge(Node* a,Node* b)
{
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;
    Node* result;
    if(a->data<b->data)
    {
        result=a;
        result->next=merge(a->next,b);
    }
    else
    {
        result=b;
        result->next=merge(a,b->next);
    }
    return result;
}

void mergesort(Node **headref)
{
    Node *head=*headref,*a=NULL,*b=NULL;
    if(head==NULL || head->next==NULL)
        return;
    splitFrontandback(head,&a,&b);
    
    mergesort(&a);
    mergesort(&b);
    
    *headref=merge(a,b);
}

/* Function to mergesort the linked list
   It should return head of the modified list  */
Node* mergeSort(Node* head) {
    // your code here
    mergesort(&head);
    return head;
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