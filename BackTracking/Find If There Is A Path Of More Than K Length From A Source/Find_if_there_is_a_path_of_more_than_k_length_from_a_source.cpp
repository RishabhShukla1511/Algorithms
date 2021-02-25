#include<bits/stdc++.h>
using namespace std;

bool check(int reqweight,int s,int sum,vector<pair<int,int>>graph[],vector<int>&path,vector<int>&visited)
{
    if(visited[s]==1)
        return false;
    if(sum>reqweight)
    {
        cout << "YES\nPath: ";
        for(int i=0;i<path.size()-1;i++)
            cout << path[i] << "->";
        cout << path[path.size()-1] << "\nCost: " << sum << '\n';
        return true;
    }
    visited[s]=1;
    for(int i=0;i<graph[s].size();i++)
    {
        if(visited[graph[s][i].first]==0)
        {
            path.push_back(graph[s][i].first);
            if(check(reqweight,graph[s][i].first,sum+graph[s][i].second,graph,path,visited))
                return true;
            path.pop_back();
            visited[graph[s][i].first]=0;
        }
    }
    return false;
}

int main()
{
    int n,e;
    cout << "Enter the number of vertices\n";
    cin >> n;
    cout << "Enter the number of edges\n";
    cin >> e;
    vector<pair<int,int>>graph[n];
    cout << "Enter the source destination and weight of the edge\n";
    for(int i=1;i<=e;i++)
    {
        cout << "For edge " << i << " ";
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    int source;
    cout << "Enter the source\n";
    cin >> source;
    if(source<0 || source>n)
        cout << "Enter a valid source\n";
    else
    {
        int reqweight;
        cout << "Enter the required weight\n";
        cin >> reqweight;
        vector<int>visited;
        for(int i=0;i<n;i++)
            visited.push_back(0);
        vector<int>path;
        path.push_back(source);
        if(!check(reqweight,source,0,graph,path,visited))
            cout << "No path found with cost greater than " << reqweight << '\n';
    }    
}