#include<bits/stdc++.h>
using namespace std;

int numberofTriangles(vector<vector<int>>&graph,int V,int k)
{
    int cnt=0;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            for(int k=0;k<V;k++)
            {
                if(graph[i][j] && graph[j][k] && graph[k][i])
                    cnt++;
            }
        }
    }
    if(k==0)
        return cnt/6;
    return cnt/3;
}

int main()
{
    int k=0;
    cout << "Press y if the graph is directed or any other key if the graph is undirected\n";
    char c;
    cin >> c;
    if(c=='y' || c=='Y')
        k=1;
    int V,E;
    cout << "Enter the total number of vertices\n";
    cin >> V;
    cout << "Enter the total number of edges\n";
    cin >> E;
    vector<vector<int>>graph;
    vector<int>temp(V);
    fill(temp.begin(),temp.end(),0);
    for(int i=0;i<V;i++)
        graph.push_back(temp);
    for(int i=1;i<=E;i++)
    {
        cout << "start and end vertex of " << i << " edge\n";
        int a,b;
        cin >> a >> b;
        if(a<0 || a>=V || b<0 || b>=V)
        {
            cout << "Invalid entry\n";
            return 0;
        }
        if(k==0)
        {
            graph[a][b]=1;
            graph[b][a]=1;
        }
        else
            graph[a][b]=1;
    }
    cout << "Total number of triangles: " << numberofTriangles(graph,V,k);
}