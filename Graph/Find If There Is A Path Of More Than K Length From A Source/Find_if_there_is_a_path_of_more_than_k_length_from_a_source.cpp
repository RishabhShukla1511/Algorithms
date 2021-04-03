#include<bits/stdc++.h>
using namespace std;

void pathMoreThank(vector<pair<int,int>>graph[],int s,int path[],int len,int k,string &ans)
{
    if(len>k)
    {
        ans="Yes";
        return;
    }
    for(int i=0;i<graph[s].size();i++)
    {
        if(path[graph[s][i].first]==0)
        {
            path[graph[s][i].first]=1;
            pathMoreThank(graph,graph[s][i].first,path,len+graph[s][i].second,k,ans);
            path[graph[s][i].first]=0;
        }
    }
    return;
}

int main()
{
    int V,E;
    cout << "Enter the number of vertices - start from 0\n";
    cin >> V;
    cout << "Enter the number of edges\n";
    cin >> E;
    vector<pair<int,int>>Graph[V];
    int k=0;
    for(int i=1;i<=E;i++)
    {
        int s,d,w;
        cout << "Enter the start,end vertex and weight for " << i << " edge\n";
        cin >> s >> d >> w;
        if(s<0 || s>=V || d<0 || d>=V)
        {
            k=1;
            cout << "Invalid entry\n";
            break;
        }
        Graph[s].push_back({d,w});
        Graph[d].push_back({s,w});
    }
    if(k==0)
    {
        int s;
        cout << "Enter the source vertex\n";
        cin >> s;
        if(s<0 || s>=V)
            cout << "Invalid entry\n";
        else
        {
            int k;
            cout << "Enter K\n";
            cin >> k;
            int path[V]={0};
            path[s]=1;
            string ans="No";
            pathMoreThank(Graph,s,path,0,k,ans);
            cout << ans << '\n';
        }
    }
}