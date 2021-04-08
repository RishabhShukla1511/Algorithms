#include<bits/stdc++.h>
using namespace std;

bool isBipartite(vector<int>graph[],int V)
{
    int color[V];
    memset(color,-1,sizeof(color));
    queue<int>q;
    for(int k=0;k<V;k++)
    {
        if(color[k]!=-1)
            continue;
        q.push(k);
        color[k]=0;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=1;i<=n;i++)
            {
                int ver=q.front();
                q.pop();
                int col=0;
                if(color[ver]==0)
                    col=1;
                for(int j=0;j<graph[ver].size();j++)
                {
                    int v=graph[ver][j];
                    if(color[v]==-1)
                    {
                        color[v]=col;
                        q.push(v);
                    }
                    else if(color[v]==color[ver])
                        return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    cout << "Press d if the graph is directed any other key if undirected\n";
    char c;
    cin >> c;
    int V,E;
    cout << "Enter the number of vertices\n";
    cin >> V;
    cout << "Enter the number of edges\n";
    cin >> E;
    vector<int>graph[V];
    cout << "Enter the edges\nVertices are labelled from 0\n";
    for(int i=1;i<=E;i++)
    {
        cout << "Enter the start and end vertex of " << i << " edge\n";
        int a,b;
        cin >> a >> b;
        if(a<0 || a>=V || b<0 || b>=V)
        {
            cout << "Invalid entry\n";
            return 0;
        }
        if(c=='d' || c=='D')
            graph[a].push_back(b);
        else
        {
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    }
    if(isBipartite(graph,V))
        cout << "Graph is Bipartite\n";
    else
        cout << "Graph is not Bipartite\n";
}