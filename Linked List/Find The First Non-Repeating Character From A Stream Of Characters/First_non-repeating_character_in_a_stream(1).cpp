#include<bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node *next,*prev;
    Node(char val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void firstNonrep(Node *head,Node *tail,string stream)
{
    Node *inDLL[256];
    bool isrepeated[256];
    for(int i=0;i<256;i++)
    {
        inDLL[i]=NULL;
        isrepeated[i]=false;
    }
    int n=stream.size();
    for(int i=0;i<n;i++)
    {
        char val=stream[i];
        if(!isrepeated[val])
        {
            if(inDLL[val]==NULL)
            {
                Node *temp=new Node(val);
                if(head==NULL)
                {
                    head=temp;
                    tail=temp;
                }
                else
                {
                    tail->next=temp;
                    temp->prev=tail;
                    tail=tail->next;   
                }                
                inDLL[val]=tail;
            }
            else
            {
                Node *temp=inDLL[val]; 
                if(temp==head)
                    head=head->next;
                if(temp==tail)
                    tail=tail->prev;             
                if(temp->prev)
                    temp->prev->next=temp->next;
                if(temp->next)
                    temp->next->prev=temp->prev;
                delete (temp); 
                inDLL[val]=NULL;
                isrepeated[val]=true;               
            }            
        }
        if(head)
            cout << head->data << " ";
        else
            cout << "-1 ";
    }
    cout << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        Node *head=NULL,*tail=NULL;
        string stream="";
        for(int i=1;i<=n;i++)
        {
            string a;
            cin >> a;
            stream+=a;
        }
        firstNonrep(head,tail,stream);
    }
}