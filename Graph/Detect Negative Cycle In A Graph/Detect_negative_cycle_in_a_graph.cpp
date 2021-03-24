#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;

struct Edge{
    int a,b,weight;
    Edge(int a,int b,int weight)
    {
        this->a=a;
        this->b=b;
        this->weight=weight;
    }
};

bool negCycleExists(vector<Edge*>edges,int V,int ver,int visited[])
{
    int dist[V],m=edges.size(),x=-1;
    visited[ver]=1;
    fill(dist,dist+V,INF);
    dist[ver]=0;
    for(int i=0;i<V;i++)
    {
        x=-1;
        for(int j=0;j<m;j++)
        {
            if(dist[edges[j]->a]<INF && dist[edges[j]->b]>dist[edges[j]->a]+edges[j]->weight)
            {
                dist[edges[j]->b]=max(-INF,dist[edges[j]->a]+edges[j]->weight);
                x=edges[j]->b;
                visited[edges[j]->b]=1;
            }
        }
    }
    return (x!=-1);
}

int main()
{
    int V,E;
    cout << "Enter the total number of vertices\n";
    cin >> V;
    cout << "Enter the total number of edges\n";
    cin >> E;
    vector<Edge*>edges;
    for(int i=1;i<=E;i++)
    {
        cout << "Enter the start, end vertex and weight of " << i << " edge\n";
        int a,b,w;
        cin >> a >> b >> w;
        Edge* edge=new Edge(a,b,w); 
        edges.push_back(edge);
    }
    int visited[V]={0};
    for(int i=0;i<V;i++)
    {
        if(!visited[i] && negCycleExists(edges,V,i,visited))
        {
            cout << "Negative cycle exists\n";
            return 0;
        }
    }
    cout << "No negative cycle exists\n";
    return 0;
}