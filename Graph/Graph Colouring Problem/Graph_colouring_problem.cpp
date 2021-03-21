#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int>graph[],int a,int b)
{
    graph[a].push_back(b);
    graph[b].push_back(a);
    return;
}

void print(int color[],int V)
{
    cout << "Vertex\tColor\n";
    for(int i=0;i<V;i++)
        cout << i << "\t" << color[i] << '\n';
    return;
}

void colorGraph(vector<int>graph[],int V)
{
    int color[V]={0};
    color[0]=1;
    for(int i=1;i<V;i++)
    {
        unordered_map<int,int>m;
        for(int j=0;j<graph[i].size();j++)
            m[color[graph[i][j]]]++;
        int val=0;
        for(val=1;val<=V;val++)
        {
            if(m[val]==0)
                break;
        }
        color[i]=val;
    }
    print(color,V);
    return;
}

int main()
{
    cout << "Graph Coloring Problem - Greedy Approach - Upper bound on the number of colors required to color graph - Less than number of vertices\n";
    int V,E;
    cout << "Enter the number of vertices\n";
    cin >> V;
    cout << "Enter the number of edges\n";
    cin >> E;
    cout << "Enter the edges\nVertices are laballed from 0\n";
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
        addEdge(graph,a,b);
    }
    if(k==0)
    {
        cout << "Coloring\n";
        colorGraph(graph,V);
    }
    return 0;
}