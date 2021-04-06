#include<bits/stdc++.h>
using namespace std;

int minRevEdges(vector<int>graph[],vector<vector<int>>adjmat,int s,int d,int V)
{
    queue<pair<int,int>>q;
    int steps[V];
    for(int i=0;i<V;i++)
        steps[i]=INT_MAX;
    steps[s]=0;
    q.push({s,0});
    while(!q.empty())
    {
        int n=q.size();
        for(int i=1;i<=n;i++)
        {
            int ver=q.front().first,cnt=q.front().second;
            q.pop();
            for(int j=0;j<graph[ver].size();j++)
            {
                int nextver=graph[ver][j];
                if(adjmat[ver][nextver] && cnt<steps[nextver])
                {
                    q.push({nextver,cnt});
                    steps[nextver]=cnt;
                }
                else if(adjmat[ver][nextver]==0 && cnt+1<steps[nextver])
                {
                    q.push({nextver,cnt+1});
                    steps[nextver]=cnt+1;
                }
            }
        }
    }
    if(steps[d]==INT_MAX)
        return -1;
    return steps[d]; 
}

int main()
{
    int V,E;
    cout << "Enter total number of vertices\n";
    cin >> V;
    cout << "Enter total number of edges\n";
    cin >> E;
    vector<vector<int>>adjmat;
    vector<int>temp(V);
    fill(temp.begin(),temp.end(),0);
    for(int i=0;i<V;i++)
        adjmat.push_back(temp);
    vector<int>graph[V];
    for(int i=1;i<=E;i++)
    {
        cout << "Enter start and end vertex of " << i << " edge\n";
        int a,b;
        cin >> a >> b;
        if(a<0 || a>=V || b<0 || b>=V)
        {
            cout << "Invalid entry\n";
            return 0;
        }
        graph[a].push_back(b);
        graph[b].push_back(a);
        adjmat[a][b]=1;
    }
    int s;
    cout << "Enter the source vertex\n";
    cin >> s;
    if(s<0 || s>=V)
    {
        cout << "Invalid entry\n";
        return 0;
    }
    int d;
    cout << "Enter the destination vertex\n";
    cin >> d;
    if(d<0 || d>=V)
    {
        cout << "Invalid entry\n";
        return 0;
    }
    int ans=minRevEdges(graph,adjmat,s,d,V);
    if(ans==-1)
        cout << "Impossible to reach " << d << " from " << s;
    else
        cout << "Minimum edges to reverse to reach " << d << " from " << s << ": " << ans;
}