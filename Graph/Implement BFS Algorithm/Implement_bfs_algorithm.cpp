#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<int>Graph[],int visited[],int n,int source)
{
    vector<int>bfstrav;
    queue<int>q;
    q.push(source);
    while(!q.empty())
    {
        int n=q.size();
        for(int i=1;i<=n;i++)
        {
            int ver=q.front();
            q.pop();
            if(!visited[ver])
            {
                visited[ver]=1;
                bfstrav.push_back(ver);
                for(auto v:Graph[ver])
                    q.push(v);
            }    
        }
    }
    return bfstrav;
}

void printGraph(vector<int>Graph[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(auto val:Graph[i])
            cout << val << " ";
        cout << '\n';
    }
    return;
}

void printVec(vector<int>v)
{
    for(auto i:v)
        cout << i << " ";
    return;
}

int main()
{
    int V,E;
    cout << "Enter the number of vertices - start from 0\n";
    cin >> V;
    cout << "Enter the number of edges\n";
    cin >> E;
    vector<int>Graph[V];
    int k=0;
    for(int i=1;i<=E;i++)
    {
        int s,d;
        cout << "Enter the source and destination vertex for " << i << " edge\n";
        cin >> s >> d;
        if(s<0 || s>=V || d<0 || d>=V)
        {
            k=1;
            cout << "Invalid entry\n";
            break;
        }
        Graph[s].push_back(d);
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
            cout << "Folowing is the BFS : ";
            int visited[V]={0};
            vector<int>bfstrav=bfs(Graph,visited,V,s);
            printVec(bfstrav);
            for(int i=0;i<V;i++)
            {
                if(!visited[i])
                {
                    bfstrav=bfs(Graph,visited,V,i);
                    printVec(bfstrav);
                }
            }
        }
    }
    return 0;
}