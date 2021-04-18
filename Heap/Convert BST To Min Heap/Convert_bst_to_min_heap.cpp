#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int data)
    {
        this->data=data;
        left=right=NULL;
    }
};  

Node *insert(Node *root,int val)
{
    if(root==NULL)
    {
        root=new Node(val);
        return root;
    }
    if(root->data>val)
        root->left=insert(root->left,val);
    else
        root->right=insert(root->right,val);
}

void inOrder(Node *root,vector<int>&inordertrav)
{
    if(!root)
        return;
    inOrder(root->left,inordertrav);
    inordertrav.push_back(root->data);
    inOrder(root->right,inordertrav);
    return;
}

Node *preOrder(Node *root,vector<int>inordertrav,int &pos)
{
    if(pos==inordertrav.size())
        return NULL;
    root=new Node(inordertrav[pos++]);
    root->left=preOrder(root->left,inordertrav,pos);
    root->right=preOrder(root->right,inordertrav,pos);
    return root;
}

Node *BSTtoMinHeap(Node *root)
{
    vector<int>inordertrav;
    inOrder(root,inordertrav);
    int pos=0;
    root=preOrder(root,inordertrav,pos);
    return root;
}

void preOrderTravsersal(Node *root)
{
    if(!root)
        return;
    cout << root->data << " ";
    preOrderTravsersal(root->left);
    preOrderTravsersal(root->right);
    return;
}

int main()
{
    int n;
    cout << "Enter the number of nodes in BST\n";
    cin >> n;
    cout << "Enter the values to be inserted in BST\n";
    Node *root=NULL;
    while(n--)
    {
        int val;
        cin >> val;
        root=insert(root,val);
    }
    root=BSTtoMinHeap(root);
    cout << "Pre Order Travsersal of Min Heap: ";
    preOrderTravsersal(root);
    return 0;
}