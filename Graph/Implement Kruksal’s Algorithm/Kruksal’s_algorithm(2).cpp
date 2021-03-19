// Time Complexity - O(E*logV)
#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int u,v,w;
    Edge(int u,int v,int w)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }
};

void make_set(int parent[],int V)
{
    for(int i=0;i<V;i++)
        parent[i]=i;
    return;
}

int find_set(int ver,int parent[])
{
    if(parent[ver]==ver)
        return ver;
    return parent[ver]=find_set(parent[ver],parent);
}

void union_sets(int u,int v,int parent[],int rank[])
{
    int a=find_set(u,parent),b=find_set(v,parent);
    if(a!=b)
    {
        if(rank[a]<rank[b])
            swap(a,b);
        parent[b]=a;
        if(rank[a]==rank[b])
            rank[a]++;
    }
    return;
}

void printMST(vector<Edge*>edges)
{
    int mstw=0,n=edges.size();
    cout << "Following are the edges in MST\n";
    for(int i=0;i<n;i++)
    {
        cout << edges[i]->u << " --> " << edges[i]->v << "\t" << edges[i]->w << '\n';
        mstw+=edges[i]->w;
    }
    cout << "MST weight: " << mstw << '\n';
    return;
}

void kruskalMST(vector<Edge*>edges,int parent[],int rank[],int V)
{
    vector<Edge*>finalmst;
    int n=0;
    for(int i=0;i<edges.size();i++)
    {
        Edge *edge=edges[i];
        if(find_set(edge->u,parent)!=find_set(edge->v,parent))
        {
            finalmst.push_back(edge);
            union_sets(edge->u,edge->v,parent,rank);
            n++;
        }
        if(n==V-1)
            break;
    }
    printMST(finalmst);
    return;
}

bool cmp(Edge *edge1,Edge *edge2)
{
    return edge1->w<edge2->w;
}

int main()
{
    int V;
    cout << "Enter the number of vertices\n";
    cin >> V;
    int E;
    cout << "Enter the number of edges\n";
    cin >> E;
    cout << "Enter the edges\nVerices should be in [0," << V-1 << "] range\n";
    vector<Edge*>edges;
    int k=0;
    for(int i=1;i<=E;i++)
    {
        cout << "Enter the starting and ending vertices of " << i << " edge along with its weight - Separated by space\n";
        int u,v,w;
        cin >> u >> v >> w;
        if(u<0 || u>=V || v<0 || v>=V)
        {
            cout << "Invalid entry\n";
            k=1;
            break;
        }
        Edge *edge=new Edge(u,v,w);
        edges.push_back(edge);
    }
    if(k==0)
    {
        int parent[V],rank[V]={0};
        make_set(parent,V);
        sort(edges.begin(),edges.end(),cmp);
        kruskalMST(edges,parent,rank,V);
    }
    return 0;
}