#include<bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

struct custom_hash {static uint64_t splitmix64(uint64_t x) {x += 0x9e3779b97f4a7c15;x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;x = (x ^ (x >> 27)) * 0x94d049bb133111eb;return x ^ (x >> 31);}
size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x + FIXED_RANDOM);}};

struct Node{
    char data;
    Node *next,*prev;
    Node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void create(Node **head,int val)
{
    Node *newNode = new Node(val);
    if(*head==NULL)
        *head=newNode;
    else
    {
        Node *temp=*head;
        while(temp->next)
            temp=temp->next;
        temp->next=newNode;
        newNode->prev=temp;   
    }       
}

void nonRepchar(Node *head)
{
    queue<char>q;
    unordered_map<char,int,custom_hash>m;
    while(head)
    {
        char val=head->data;
        m[val]++;
        while(!q.empty() && m[q.front()]>1)
            q.pop();
        if(m[val]==1)
            q.push(val);
        if(!q.empty())
            cout << q.front() << " ";
        else
            cout << "-1 ";
        head=head->next;
    }
    cout << '\n';
}

int main()
{
    fastIO();
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        Node *head=NULL;
        for(int i=0;i<n;i++)
        {
            char val;
            cin >> val;
            create(&head,val);
        }
        nonRepchar(head);
    }
}