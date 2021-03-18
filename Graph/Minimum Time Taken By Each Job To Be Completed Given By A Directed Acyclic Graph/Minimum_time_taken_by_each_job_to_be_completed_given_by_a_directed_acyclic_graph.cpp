#include<bits/stdc++.h>
using namespace std;

vector<int> minTime(vector<int>graph[],int n)
{
    vector<int>ans(n);
    int indegree[n]={0},visited[n]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<graph[i].size();j++)
            indegree[graph[i][j]]++;
        ans[i]=0;
    }
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
            visited[i]=1;
        }
    }
    int t=0;
    while(!q.empty())
    {
        int nn=q.size();
        for(int i=1;i<=nn;i++)
        {
            int ver=q.front();
            q.pop();
            ans[ver]=t+1;
            for(int j=0;j<graph[ver].size();j++)
            {
                indegree[graph[ver][j]]--;
                if(indegree[graph[ver][j]]==0)
                {
                    visited[graph[ver][j]]=1;
                    q.push(graph[ver][j]);
                }
            }
        }
        t++;
    }
    return ans;
}

int main()
{
    cout << "Enter the number of nodes\n";
    int n;
    cin >> n;
    vector<int>graph[n];
    cout << "Enter the number of edges\n";
    int e;
    cin >> e;
    cout << "Enter edges\n";
    while(e--)
    {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    vector<int>ans=minTime(graph,n);
    int t=ans.size(),maxval=0;
    cout << "Following is the schedule\n";
    for(int i=0;i<t;i++)
    {
        cout << ans[i] << " ";
        maxval=max(maxval,ans[i]);
    }
    cout << "\nMinimum time taken to complete all jobs: " << maxval << '\n';
}