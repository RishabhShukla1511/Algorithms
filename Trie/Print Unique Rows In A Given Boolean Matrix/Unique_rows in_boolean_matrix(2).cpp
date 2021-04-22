#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	vector<vector<int>> vec = uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}
// } Driver Code Ends

struct Node
{
    Node *children[2];
    bool isend;
    Node()
    {
        for(int i=0;i<2;i++)
            children[i]=NULL;
        isend=false;
    }
};

bool insert(Node *root,int M[MAX][MAX],int row,int col)
{
    Node *temp=root;
    for(int i=0;i<col;i++)
    {
        if(!temp->children[M[row][i]])
            temp->children[M[row][i]]=new Node();
        temp=temp->children[M[row][i]];
    }
    if(temp->isend)
        return false;
    temp->isend=true;
    return true;
}

/*You are required to complete this function*/
vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
    //Your code here
    Node *root=new Node();
    vector<vector<int>>ans;
    for(int i=0;i<row;i++)
    {
        if(insert(root,M,i,col))
        {
            vector<int>v;
            for(int j=0;j<col;j++)
                v.push_back(M[i][j]);
            ans.push_back(v);
        }
    }
    return ans;
}