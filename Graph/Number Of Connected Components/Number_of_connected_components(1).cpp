#include<bits/stdc++.h>
using namespace std;

void make_set(int parent[],int rank[],int n)
{
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        rank[i]=0;
    }
}

int find_set(int parent[],int ver)
{
    if(ver==parent[ver])
        return ver;
    return parent[ver]=find_set(parent,parent[ver]);
}

int numConnectedComp(vector<pair<int,int>>v,int n)
{
    int rank[n],parent[n];
    make_set(parent,rank,n);
    int e=v.size();
    for(int i=0;i<e;i++)
    {
        int s=v[i].first,d=v[i].second,a=find_set(parent,s),b=find_set(parent,d);
        if(a!=b)
        {
            if(rank[a]<rank[b])
                swap(a,b);
            parent[b]=a;
            if(rank[a]==rank[b])
                rank[a]++;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(parent[i]==i)
            ans++;
    }
    return ans;
}

int main()
{
    cout << "Undirected graph\n";
    int V,E;
    cout << "Enter the number of vertices\n";
    cin >> V;
    cout << "Enter the number of edges\n";
    cin >> E;
    vector<pair<int,int>>v;
    cout << "Enter the edges\nVertices are labelled from 0\n";
    int k=0;
    for(int i=1;i<=E;i++)
    {
        cout << "Enter the start and end vertex\n";
        int s,d;
        cin >> s >> d;
        if(s<0 || s>=V || d<0 || d>=V)
        {
            cout << "Invlalid entry\n";
            k=1;
            break;
        }
        v.push_back({s,d});
    }
    if(k==0)
        cout << "Number of connected components = " << numConnectedComp(v,V);
}