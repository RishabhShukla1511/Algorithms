#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;

vector<int> topoSort(int V, vector<pair<int,int>> adj[]) 
{
    int indegree[V]={0},visited[V]={0};
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<adj[i].size();j++)
            indegree[adj[i][j].first]++;
    }
    queue<int>q;
    for(int i=0;i<V;i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    vector<int>topsort;
    while(!q.empty())
    {
        int ver=q.front();
        q.pop();
        visited[ver]=1;
        topsort.push_back(ver);
        for(int i=0;i<adj[ver].size();i++)
        {
            if(visited[adj[ver][i].first]==0)
            {
                indegree[adj[ver][i].first]--;
                if(indegree[adj[ver][i].first]==0)
                    q.push(adj[ver][i].first);
            }
        }
    }
    return topsort;
}

void print(vector<int>dist,int ver)
{
    cout << "Following are the longest distances from " << ver << "\nVertex\tDistance\n";
    for(int i=0;i<dist.size();i++)
    {
        cout << i << "\t";
        if(dist[i]==-INF)
            cout << "INF\n";
        else
            cout << dist[i] << '\n';
    }
    cout << '\n'; 
}

void longestPathDAG(vector<int>v,vector<pair<int,int>>adj[],int ver,int V)
{
    vector<int>dist(V,-INF);
    dist[ver]=0; 
    for(int k=0;k<V;k++)
    {
        int i=v[k];
        if(dist[i]!=-INF)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                if(dist[adj[i][j].first]<dist[i]+adj[i][j].second)
                    dist[adj[i][j].first]=dist[i]+adj[i][j].second;
            }
        }
    }
    print(dist,ver);
}

int main()
{
    cout << "Longest path in a Directed Acyclic Graph from a source vertex\n";
    int V,E;
    cout << "Enter the number of vertices - labelled from 0\n";
    cin >> V;
    cout << "Enter the number of edges\n";
    cin >> E;
    vector<pair<int,int>>Graph[V];
    int k=0;
    for(int i=1;i<=E;i++)
    {
        int s,d,w;
        cout << "Enter the source, destination vertex and weight for " << i << " edge\n";
        cin >> s >> d >> w;
        if(s<0 || s>=V || d<0 || d>=V)
        {
            k=1;
            cout << "Invalid entry\n";
            break;
        }
        Graph[s].push_back({d,w});
    }
    if(k==0)
    {
        cout << "Enter the source vertex\n";
        int ver;
        cin >> ver;
        if(ver<0 || ver>=V)
            cout << "Invalid entry\n";
        else
        {
            vector<int>topsort=topoSort(V,Graph);
            longestPathDAG(topsort,Graph,ver,V);
        }
    }
    return 0;
}