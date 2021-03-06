#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void topView(struct Node *root);


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
//        inorder(root);
//        cout<<endl;
        topView(root);
        cout << endl;
    }
    return 0;
}




// } Driver Code Ends


//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

void topview(Node* root,int d,int l,map<int,pair<int,int>>&m)
{
    if(root==NULL)
        return;
    if(m.count(d)==0)
        m[d]={l,root->data};
    else if(l<m[d].first)
        m[d]={l,root->data};
    topview(root->left,d-1,l+1,m);
    topview(root->right,d+1,l+1,m);
}

// function should print the topView of the binary tree
void topView(struct Node *root)
{
    //Your code here
    map<int,pair<int,int>>m;
    topview(root,0,0,m);
    for(auto it:m)
        cout << it.second.second << " ";
}
