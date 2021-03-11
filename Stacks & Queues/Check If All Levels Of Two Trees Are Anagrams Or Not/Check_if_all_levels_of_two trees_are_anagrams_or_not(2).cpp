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

bool allLevelAnagrams(Node *root1,Node *root2)
{
    queue<Node*>q1,q2;
    q1.push(root1);
    q2.push(root2);
    while(!q1.empty())
    {
        int n1=q1.size(),n2=q2.size();
        if(n1!=n2)
            return false;
        vector<int>temp1,temp2;
        while(n1--)
        {
            root1=q1.front();
            temp1.push_back(root1->data);
            root2=q2.front();
            temp2.push_back(root2->data);
            q1.pop();
            q2.pop();
            if(root1->left)
                q1.push(root1->left);
            if(root2->left)
                q2.push(root2->left);
            if(root1->right)
                q1.push(root1->right);
            if(root2->right)
                q2.push(root2->right);
        }
        sort(temp1.begin(),temp1.end());
        sort(temp2.begin(),temp2.end());
        if(temp1!=temp2)
            return false;
    }
    return (q1.empty() && q2.empty());
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
    
    if(allLevelAnagrams(root1,root2))
        cout << "All levels of both trees are anagrams\n";
    else
        cout << "All levels of both trees are not anagrams\n";
}