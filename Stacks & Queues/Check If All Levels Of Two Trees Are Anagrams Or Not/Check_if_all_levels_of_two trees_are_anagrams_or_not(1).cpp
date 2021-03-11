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

void levelOrder(Node *root,vector<vector<int>>&v)
{
    queue<Node*>q;
    int k=0;
    vector<int>temp;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        while(n--)
        {
            root=q.front();
            q.pop();
            temp.push_back(root->data);
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
        }
        v.push_back(temp);
    }
}

bool checkAllLevelAnagrams(vector<vector<int>>v1,vector<vector<int>>v2)
{
    int n1=v1.size(),n2=v2.size();
    if(n1!=n2)
        return false;
    for(int i=0;i<n1;i++)
        sort(v1[i].begin(),v1[i].end());
    for(int i=0;i<n2;i++)
        sort(v2[i].begin(),v2[i].end());
    for(int i=0;i<n1;i++)
    {
        if(v1[i]!=v2[i])
            return false;
    }
    return true;
}

int main()
{
    Node *root1=new Node(1);
    root1->left=new Node(3);
    root1->right=new Node(2);
    root1->right->left=new Node(5);
    root1->right->right=new Node(4);
    
    Node *root2=new Node(1);
    root2->left=new Node(2);
    root2->right=new Node(3);
    root2->right->left=new Node(4);
    root2->right->right=new Node(5);
    
    vector<vector<int>>v1,v2;
    
    levelOrder(root1,v1);
    levelOrder(root2,v2);
    
    if(checkAllLevelAnagrams(v1,v2))
        cout << "All levels are anagrams\n";
    else
        cout << "All levels are not anagrams\n";
}