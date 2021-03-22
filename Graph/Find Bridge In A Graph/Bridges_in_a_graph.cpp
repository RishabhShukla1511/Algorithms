#include<bits/stdc++.h>
using namespace std;

int timer=0;
bool isBridge(vector<int>graph[],int a,int b)
{
    int k=0;
    for(int i=0;i<graph[a].size();i++)
    {
        if(graph[a][i]==b)
            k++;
    }
    return (k==1);
}

void dfs(int ver,int p,int tin[],int low[],bool visited[],vector<int>graph[],vector<pair<int,int>>&bridge)
{
    tin[ver]=low[ver]=timer++;
    visited[ver]=true;
    for(int i=0;i<graph[ver].size();i++)
    {
        int to=graph[ver][i];
        if(to==p)
            continue;
        if(visited[to])
            low[ver]=min(low[ver],tin[to]);
        else
        {
            dfs(to,ver,tin,low,visited,graph,bridge);
            low[ver]=min(low[ver],low[to]);
            if(low[to]>tin[ver] && isBridge(graph,ver,to))
                bridge.push_back({ver,to});
        }
    }
    return;
}

void print(vector<pair<int,int>>bridge)
{
    if(bridge.size()==0)
    {
        cout << "No Bridge in given graph\n";
        return;
    }
    cout << "Following edges are the bridges in graph\n";
    for(int i=0;i<bridge.size();i++)
        cout << bridge[i].first << " " << bridge[i].second << '\n';
    return;
}

void find_bridges(vector<int>graph[],int V)
{
    bool visited[V];
    int tin[V],low[V];
    memset(visited,false,sizeof(visited));
    memset(tin,-1,sizeof(tin));
    memset(low,-1,sizeof(low));
    vector<pair<int,int>>bridge;
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
            dfs(i,-1,tin,low,visited,graph,bridge);
    }
    print(bridge);
    return;
}

int main()
{
    int V,E;
    cout << "Enter the number of vertices\n";
    cin >> V;
    cout << "Enter the number of edges\n";
    cin >> E;
    cout << "Enter edges\nVertices are labelled from 0\n";
    vector<int>graph[V];
    int k=0;
    for(int i=1;i<=E;i++)
    {
        cout << "Enter the start and end vertex of " << i << " edge\n";
        int a,b;
        cin >> a >> b;
        if(a<0 || a>=V || b<0 || b>=V)
        {
            cout << "Invalid entry\n";
            k=1;
            break;
        }
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    if(k==0)
        find_bridges(graph,V);
    return 0;
}