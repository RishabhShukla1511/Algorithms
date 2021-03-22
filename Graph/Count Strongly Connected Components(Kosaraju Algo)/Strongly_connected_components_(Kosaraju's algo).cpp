#include<bits/stdc++.h>
using namespace std;

void dfs1(int ver,vector<int>g[],bool visited[],vector<int>&order)
{
    visited[ver]=true;
    for(int i=0;i<g[ver].size();i++)
    {
        if(!visited[g[ver][i]])
            dfs1(g[ver][i],g,visited,order);
    }
    order.push_back(ver);
    return;
}

void dfs2(int ver,vector<int>gr[],bool visited[],vector<int>&component)
{
    visited[ver]=true;
    component.push_back(ver);
    for(int i=0;i<gr[ver].size();i++)
    {
        if(!visited[gr[ver][i]])
            dfs2(gr[ver][i],gr,visited,component);
    }
    return;
}

void print(vector<int>v)
{
    int n=v.size();
    for(int i=0;i<n;i++)
        cout << v[i] << " ";
    cout << '\n';
    return;
}

int main()
{
    cout << "Number of strongly connected components in directed graph - Kosaraju Algo\n";
    int V,E;
    cout << "Enter the number of vertices\n";
    cin >> V;
    cout << "Enter the number of edges\n";
    cin >> E;
    cout << "Enter the edges\nVertices are labelled from 0\n";
    vector<int>g[V],gr[V];
    int k=0;
    for(int i=1;i<=E;i++)
    {
        cout << "Enter the start and end vertex of " << i << " edge\n";
        int a,b;
        cin >> a >> b;
        if(a<0 || a>=V || b<0 || b>=V)
        {
            k=1;
            cout << "Invalid entry\n";
            break;
        }
        g[a].push_back(b);
        gr[b].push_back(a);
    }
    if(k==0)
    {
        bool visited[V];
        memset(visited,false,sizeof(visited));
        vector<int>order;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
                dfs1(i,g,visited,order);
        }
        memset(visited,false,sizeof(visited));
        cout << "Strongly connected components\n";
        for(int i=0;i<V;i++)
        {
            int ver=order[V-1-i];
            if(!visited[ver])
            {
                vector<int>component;
                dfs2(ver,gr,visited,component);
                print(component);
            }
        }
    }
    return 0;
}