#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;
 
struct Edge{
    int a,b,weight;  
    Edge(int a,int b,int w)
    {
        this->a=a;
        this->b=b;
        this->weight=w;
    }
};
 
void printMinDistPath(int dist[],int parent[],int ver)
{
    vector<int>path;
    while(ver!=-1)
    {
        path.push_back(ver);
        ver=parent[ver];
    }
    reverse(path.begin(),path.end());
    for(int i=0;i<path.size()-1;i++)
        cout << path[i] << " -> ";
    cout << path[path.size()-1];
    return;
}
 
void bellman_ford(vector<Edge*>edges,int V,int s)
{
    int dist[V],parent[V],n=edges.size(),x=-1;
    fill(dist,dist+V,INF);
    fill(parent,parent+V,-1);
    dist[s]=0;
    for(int i=0;i<V;i++)
    {
        x=-1;
        for(int j=0;j<edges.size();j++)
        {
            if(dist[edges[j]->a]<INF && dist[edges[j]->b]>dist[edges[j]->a]+edges[j]->weight)
            {
                dist[edges[j]->b]=max(-INF,dist[edges[j]->a]+edges[j]->weight);
                parent[edges[j]->b]=edges[j]->a;
                x=edges[j]->b;
            }
        }
    }
    if(x==-1)
    {
        cout << "Minimum distance path to all other vertices\nVertex\tDist\tPath\n";
        for(int i=0;i<V;i++)
        {
            cout << i << "\t";
            if(dist[i]==INF)
                cout << "INF\t-";
            else
            {
                cout << dist[i] << "\t";
                printMinDistPath(dist,parent,i);
            }
            cout << '\n';
        }
    }
    else
    {
        cout << "Cycle is present: ";
        vector<int>cycle;
        int y=x,cnt=0;
        for(int i=0;i<V;i++)
            y=parent[y];
        while(1)
        {
            cycle.push_back(y);
            cnt++;
            y=parent[y];
            if(y==x && cnt>1)
                break;
        }
        reverse(cycle.begin(),cycle.end());
        for(int i=0;i<cycle.size();i++)
            cout << cycle[i] << " ";
        cout << '\n';
    }
    return;
}
 
int main()
{
    cout << "C++ Implementation of Bellman-Ford Algorithm\nAbout the Implementation\n1) Time Complexity - O(V*E)\n2) Space complexity - O(E+V)\n";
    cout << "3) Vertices are labelled from 0\n4) Unreachable vertices are given " << INT_MAX << " path distance\n";
    cout << "5) This is an improvised version which works for negative cycles too and prints the paths of shortest paths\n\n\n";
    int V,E;
    cout << "Enter the total number of vertices\n";
    cin >> V;
    cout << "Enter the total number of edges\n";
    cin >> E;
    vector<Edge*>edges;
    int k=0;
    for(int i=1;i<=E;i++)
    {
        cout << "Enter the start, end vertex and weight of " << i << " edge - Separate each by space\n";
        int a,b,w;
        cin >> a >> b >> w;
        if(a<0 || a>=V || b<0 || b>=V)
        {
            cout << "Invalid entry vertices should be in [0," << V << "] range\n";
            k=1;
            break;
        }
        Edge* edge=new Edge(a,b,w);
        edges.push_back(edge);
    }
    cout << "Enter the source vertex\n";
    int s;
    cin >> s;
    if(s<0 ||s>=V)
        cout << "Invalid entry vertices should be in [0," << V << "] range\n";
    else
        bellman_ford(edges,V,s);
    return 0;
}

