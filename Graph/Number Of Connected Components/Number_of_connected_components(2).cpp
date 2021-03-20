#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>v[],int ver,int visited[])
{
    visited[ver]=1;
    for(int i=0;i<v[ver].size();i++)
    {
        if(visited[v[ver][i]]==0)
            dfs(v,v[ver][i],visited);
    }
}

int NoOfConnectedComponents(vector<int>v[],int i,int noofvertices)
{
    int visited[noofvertices+1]={0},noofconnectedcomp=0,level=0;
    for(int i=1;i<=noofvertices;i++)
    {
        if(visited[i]==0)
        {
            dfs(v,i,visited);
            noofconnectedcomp++;
        }
    }
    return noofconnectedcomp;
}

int main()
{
    cout << "Undirected graph\n";
    int noofedges,noofvertices;
    cout << "Enter the number of vertices in graph\n";
    cin >> noofvertices;
    cout << "Enter the number of edges in graph\n";
    cin >> noofedges;
    vector<int>v[noofvertices+1];
    int k=noofedges;
    for(int i=1;i<=k;i++)
    {
        cout << i << " edge\n";
        int a,b;
        cout << "Enter the starting and ending vertex\n";
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int visited[noofvertices+1]={0};

    int cc=NoOfConnectedComponents(v,1,noofvertices);
    cout << "Number of connected components = " << cc;
}