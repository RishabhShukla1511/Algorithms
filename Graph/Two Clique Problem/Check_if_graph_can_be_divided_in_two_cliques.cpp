#include<bits/stdc++.h>
using namespace std;

void getInverseGraph(vector<vector<int>>&graph)
{
    int V=graph.size();
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(i==j)
                continue;
            if(graph[i][j])
                graph[i][j]=0;
            else
                graph[i][j]=1;
        }
    }
}

bool isBipartite(vector<vector<int>>&graph)
{
    int V=graph.size();
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
                for(int j=0;j<V;j++)
                {
                    if(graph[ver][j]) 
                    {
                        if(color[j]==-1)
                        {
                            color[j]=col;
                            q.push(j);
                        }
                        else if(color[j]==color[ver])
                                return false;
                    }
                }
            }
        }
    }
    cout << "Following are the 2 cliques\n";
    for(int i=0;i<V;i++)
    {
        if(color[i])
            cout << i << " ";
    }
    cout << '\n';
    for(int i=0;i<V;i++)
    {
        if(color[i]==0)
            cout << i << " ";
    }
    return true;
}

int main()
{
    int V,E;
    cout << "Enter the number of vertices\n";
    cin >> V;
    cout << "Enter the number of edges\n";
    cin >> E;
    vector<vector<int>>graph;
    vector<int>temp(V,0);
    for(int i=0;i<V;i++)
        graph.push_back(temp);
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
        graph[a][b]=1;
        graph[b][a]=1;
    }
    getInverseGraph(graph);
    if(!isBipartite(graph))
        cout << "Not possible to divide the graph into 2 cliques\n";
}