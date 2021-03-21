#include<bits/stdc++.h>
using namespace std;

void print(int color[],int V)
{
    cout << "Vertex\tColor\n";
    for(int i=0;i<V;i++)
        cout << i << "\t" << color[i] << '\n';
    return;
}

bool cmp(pair<int,int>a,pair<int,int>b)
{
    return a.first>b.first;
}

void colorGraph(vector<vector<int>>graph,int V)
{
    int color[V]={0},indegree[V]={0};
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(graph[i][j]==1)
                indegree[j]++;
        }
    }
    vector<pair<int,int>>v;
    for(int i=0;i<V;i++)
        v.push_back({indegree[i],i});
    sort(v.begin(),v.end(),cmp);
    bool selected[V];
    int val=1;
    memset(selected,false,sizeof(selected));
    for(int i=0;i<V;i++)
    {
        while(i<V && selected[v[i].second])
            i++;
        if(i==V)
            break;
        color[v[i].second]=val;
        selected[v[i].second]=true;
        for(int j=i+1;j<V;j++)
        {
            if(!selected[v[j].second] && !graph[v[i].second][v[j].second])
            {
                color[v[j].second]=val;
                selected[v[j].second]=true;
            }
        }
        val++;
    }
    print(color,V);
    return;
}

int main()
{
    cout << "Graph Coloring Problem - Welsh Powell Algorithm - Upper bound on the number of colors required to color graph - Less than number of vertices\n";
    int V,E;
    cout << "Enter the number of vertices\n";
    cin >> V;
    cout << "Enter the number of edges\n";
    cin >> E;
    cout << "Enter the edges\nVertices are laballed from 0\n";
    vector<vector<int>>graph;
    vector<int>temp(V,0);
    for(int i=0;i<V;i++)
        graph.push_back(temp);
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
        graph[a][b]=1;
        graph[b][a]=1;
    }
    if(k==0)
    {
        cout << "Coloring\n";
        colorGraph(graph,V);
    }
    return 0;
}