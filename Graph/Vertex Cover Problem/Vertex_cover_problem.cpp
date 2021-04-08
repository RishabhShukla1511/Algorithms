#include<bits/stdc++.h>
using namespace std;

void vertexCover(vector<int>graph[],int V)
{
    bool visited[V];
    memset(visited,false,sizeof(visited));
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
        {
            for(int j=0;j<graph[i].size();j++)
            {
                int v=graph[i][j];
                if(!visited[v])
                {
                    cout << i << " " << v << " ";
                    visited[v]=true;
                    visited[i]=true;
                    break;
                }
            }
        }
    }
    return;
}

int main()
{
    cout << "Approximate Algorithm for Vertex Cover Problem\n";
    int V,E;
    cout << "Enter the number of vertices - start from 0\n";
    cin >> V;
    cout << "Enter the number of edges\n";
    cin >> E;
    vector<int>Graph[V];
    for(int i=1;i<=E;i++)
    {
        int s,d;
        cout << "Enter the source and destination vertex for " << i << " edge\n";
        cin >> s >> d;
        if(s<0 || s>=V || d<0 || d>=V)
        {
            cout << "Invalid entry\n";
            return 0;
        }
        Graph[s].push_back(d);
        Graph[d].push_back(s);
    }
    vertexCover(Graph,V);
}