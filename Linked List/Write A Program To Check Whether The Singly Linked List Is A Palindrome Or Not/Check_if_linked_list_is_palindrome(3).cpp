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

bool isPalin(int arr[],int n)
{
    for(int i=0;i<n/2;i++)
    {
        if(arr[i]!=arr[n-i-1])
            return false;
    }
    return true;
}

int lllength(Node* head)
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
    int n=lllength(head);
    int arr[n],i=0;
    while(head!=NULL)
    {
        arr[i]=head->data;
        head=head->next;
        i++;
    }
    if(isPalin(arr,n))
        return true;
    return false;
}

