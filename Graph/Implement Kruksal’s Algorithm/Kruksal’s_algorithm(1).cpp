//Time Complexity - O(E*V + E*logE)
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

void printMST(vector<Edge*>edges)
{
    int mstw=0,n=edges.size();
    cout << "Following are the edges in MST\n";
    for(int i=0;i<n;i++)
    {
        cout << edges[i]->u << "--> " << edges[i]->v << "\t" << edges[i]->w << '\n';
        mstw+=edges[i]->w;
    }
    cout << "MST weight: " << mstw << '\n';
}

void kruskalMST(vector<Edge*>edges,int V)
{
    vector<Edge*>finalmst;
    int comp[V],n=0;
    for(int i=0;i<V;i++)
        comp[i]=i;
    for(int i=0;i<edges.size();i++)
    {
        Edge *edge=edges[i];
        int a=comp[edge->u],b=comp[edge->v];
        if(a!=b)
        {
            int minv=min(a,b);
            for(int j=0;j<V;j++)
            {
                if(comp[j]==a || comp[j]==b)    
                    comp[j]=minv;
            }
            finalmst.push_back(edge);
            n++;
        }
        if(n==V-1)
            break;
    }
    printMST(finalmst);
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
        sort(edges.begin(),edges.end(),cmp);
        //printMST(edges);
        kruskalMST(edges,V);
    }
}