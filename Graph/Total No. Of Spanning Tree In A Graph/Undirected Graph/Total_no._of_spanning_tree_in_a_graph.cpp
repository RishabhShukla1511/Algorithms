#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> getMat(vector<vector<int>>adj,int r,int c)
{
    vector<vector<int>>mat;
    int n=adj.size();
    for(int i=0;i<n;i++)
    {
        if(i!=r)
        {
            vector<int>temp;
            for(int j=0;j<n;j++)
            {
                if(j!=c)
                    temp.push_back(adj[i][j]);
            }
            mat.push_back(temp);
        }
    }
    return mat;
}

int det(vector<vector<int>>adj)
{
    int n=adj.size();
    if(n==1)
        return adj[0][0];
    if(n==2)
        return ((adj[0][0]*adj[1][1])-(adj[0][1]*adj[1][0]));
    int val=0;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
            val+=adj[0][i]*det(getMat(adj,0,i));
        else
            val-=adj[0][i]*det(getMat(adj,0,i));
    }
    return val;
}

void getLaplacianMatrix(vector<vector<int>>&adj,int degree[])
{
    int n=adj.size();
    for(int i=0;i<n;i++)
        adj[i][i]=degree[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j && adj[i][j]==1)
                adj[i][j]=-1;
        }
    }   
}

void remirowjcol(vector<vector<int>>&adj)
{
    int n=adj.size();
    vector<vector<int>>temp;
    for(int i=1;i<n;i++)
    {   
        vector<int>v;
        for(int j=1;j<n;j++)
            v.push_back(adj[i][j]);
        temp.push_back(v);
    }
    adj=temp;
}

void print(vector<vector<int>>adj)
{
    int n=adj.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout << adj[i][j] << " ";
        cout << '\n'; 
    }
    cout << '\n';
}

int input()
{
    int n;
    cout << "Enter the number of nodes\n";
    cin >> n;
    if(n==1)
        return 0;
    int degree[n]={0};
    vector<vector<int>>adj;
    vector<int>temp(n);
    fill(temp.begin(),temp.end(),0);
    for(int i=0;i<n;i++)
        adj.push_back(temp);
    int e,k=0;
    cout << "Enter the number of edges\n";
    cin >> e;
    cout << "Vertex numbers start from 0\n";
    for(int i=1;i<=e;i++)
    {
        cout << "Enter the starting and ending vertex of " << i << " edge\n";
        int a,b;
        cin >> a >> b;
        if(a<0 || a>=n || b<0 || b>=n || a==b)
        {
            cout << "Invalid entry\n";
            k=1;
            break;
        }
        degree[a]++;
        degree[b]++;
        adj[a][b]=1;
        adj[b][a]=1;
    }
    if(k==0)
    {
        getLaplacianMatrix(adj,degree);
        remirowjcol(adj);
        return det(adj);
    }
    return -1;
}

int main()
{
    cout << "Total number of spanning tree in a Connected Undirected without self loop graph using Matrix Tree Algorithm/Kirchoff's Theorem\n";
    int totalspantree=input();
    if(totalspantree!=-1)
        cout << "Total number of Spanning Tree possible in given graph are " << totalspantree;
}