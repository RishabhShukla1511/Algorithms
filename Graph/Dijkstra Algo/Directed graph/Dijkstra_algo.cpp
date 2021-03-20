#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;

void addEdge(vector<pair<int,int>>graph[],int u,int v,int w)
{
    graph[u].push_back({v,w});
}

vector<int> dijkstraShortestPath(int ver,vector<pair<int,int>>graph[],int n)
{
    vector<int>dist(n,INF);
    vector<bool>selected(n,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,ver});
    dist[ver]=0;
    while(!pq.empty())
    {
        ver=pq.top().second;
        pq.pop();
        if(selected[ver])
            continue;
        selected[ver]=true;
        for(int i=0;i<graph[ver].size();i++)
        {
            int v=graph[ver][i].first,w=graph[ver][i].second;
            if(!selected[v] && dist[ver]+w<dist[v])
            {
                dist[v]=dist[ver]+w;
                pq.push({dist[v],v});
            }
        }
    }
    return dist;
}

void print(vector<int>dist,int s)
{
    int n=dist.size();
    cout << "Shortest distance from " << s << " to all other vertices\n";
    cout << "Source\tDestination\tShortestsDistance\n";
    for(int i=0;i<n;i++)
        cout << s << "\t" << i << "\t\t" << dist[i] << "\n";
    cout << '\n';
}

int main()
{
    cout << "Dijkstra Algorithm\nTo find shortest path between source and all other vertices\n";
    cout << "Requirements:\n1) Directed graph\n2) Non negative weighted edges\n3) Vertex are labelled from 0 to V-1\n";
    int V,E;
    cout << "Enter the number of vertices\n";
    cin >> V;
    cout << "Enter the number of edges\n";
    cin >> E;
    vector<pair<int,int>>graph[V];
    cout << "Enter the edges\nVertices are in [0," << V-1 << "] range\nWeights should be non negative\n";
    int k=0;
    for(int i=1;i<=E;i++)
    {
        cout << "Enter the starting, ending vertex and weight " << i << " edge\n";
        int u,v,w;
        cin >> u >> v >> w;
        if(u<0 || u>=V || v<0 || v>=V || w<0)
        {
            cout << "Invalid entry\n";
            k=1;
            break;
        }
        addEdge(graph,u,v,w);
    }
    if(k==0)
    {
        cout << "Enter the source vertex\n";
        int s;
        cin >> s;
        vector<int>dist=dijkstraShortestPath(s,graph,V);
        print(dist,s);
    }
}