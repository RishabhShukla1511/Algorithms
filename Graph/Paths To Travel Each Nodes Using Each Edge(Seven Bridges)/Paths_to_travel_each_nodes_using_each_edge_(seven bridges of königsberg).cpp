#include<bits/stdc++.h>
using namespace std;

bool hasEulerPath(vector<int>graph[],int V)
{
    int cnt=0;
    for(int i=0;i<V;i++)
    {
        if(graph[i].size()&1)
            cnt++;
    }
    return (cnt==0 || cnt==2);
}

void addEdge(vector<int>graph[],int u,int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void rmEdge(vector<int>graph[],int u,int v)
{
    for(int i=0;i<graph[u].size();i++)
    {
        if(graph[u][i]==v)
        {
            graph[u][i]=-1;
            break;
        }
    }
    for(int i=0;i<graph[v].size();i++)
    {
        if(graph[v][i]==u)
        {
            graph[v][i]=-1;
            break;
        }
    }
}

void dfs(vector<int>graph[],int u,bool visited[],int &cnt)
{
    visited[u]=true;
    for(int i=0;i<graph[u].size();i++)
    {
        if(graph[u][i]!=-1 && !visited[graph[u][i]])
        {
            cnt++;
            dfs(graph,graph[u][i],visited,cnt);
        }
    }
}

bool isValid(vector<int>graph[],int u,int v,int V)
{
    int cnt=0;
    for(int i=0;i<graph[u].size();i++)
    {
        if(graph[u][i]!=-1)
            cnt++;
    }
    if(cnt==1)
        return true;
    bool visited[V];
    memset(visited,false,sizeof(visited));
    int cnt1=0;
    dfs(graph,u,visited,cnt1);
    rmEdge(graph,u,v);
    memset(visited,false,sizeof(visited));
    int cnt2=0;
    dfs(graph,u,visited,cnt2);
    addEdge(graph,u,v);
    return cnt1<=cnt2;
}

void EulerPath(vector<int>graph[],int u,int V)
{
    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i];
        if(v!=-1 && isValid(graph,u,v,V))
        {
            cout << u << " " << v << '\n';
            rmEdge(graph,u,v);
            EulerPath(graph,v,V);
        }
    }
}

void printEulerPath(vector<int>graph[],int V)
{
    int u=0;
    for(int i=0;i<V;i++)
    {
        if(graph[i].size()&1)
        {
            u=i;
            break;
        }
    }
    EulerPath(graph,u,V);
}

int main()
{
    int V,E;
    cout << "Enter the number of vertices - start from 0\n";
    cin >> V;
    cout << "Enter the number of edges\n";
    cin >> E;
    vector<int>Graph[V];
    int k=0;
    for(int i=1;i<=E;i++)
    {
        int s,d;
        cout << "Enter the source and destination vertex for " << i << " edge\n";
        cin >> s >> d;
        if(s<0 || s>=V || d<0 || d>=V)
        {
            k=1;
            cout << "Invalid entry\n";
            return 0;
        }
        Graph[s].push_back(d);
        Graph[d].push_back(s);
    }
    if(k==0)
    {
        if(hasEulerPath(Graph,V))
        {
            cout << "Euler Path\n";
            printEulerPath(Graph,V);
        }
        else
            cout << "No Euler Path exists\n";
    }
}