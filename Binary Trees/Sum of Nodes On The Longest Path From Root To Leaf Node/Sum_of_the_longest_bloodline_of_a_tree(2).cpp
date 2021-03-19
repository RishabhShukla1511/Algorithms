//Initial Template for C++
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


int sumOfLongRootToLeafPath(Node* root);

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout<<sumOfLongRootToLeafPath(root)<<endl;
  }
  return 0;
}// } Driver Code Ends


//User function Template for C++
/*
structure of the node of the binary tree is as
struct Node {
	int data;
	Node* left, *right;
};
*/

void longestpath(Node *root,int level,int &maxlevel,int prev,int &ans)
{
    if(root==NULL)
        return;
    if(level==maxlevel)
        ans=max(ans,prev+root->data);
    if(level>maxlevel)
    {
        ans=prev+root->data;
        maxlevel=level;
    }
    longestpath(root->left,level+1,maxlevel,prev+root->data,ans);
    longestpath(root->right,level+1,maxlevel,prev+root->data,ans);
}

// your task is to complete this function
int sumOfLongRootToLeafPath(Node* root)
{
	// Code here
	int ans=0,maxlevel=-1;
	longestpath(root,0,maxlevel,0,ans);
	return ans;
}