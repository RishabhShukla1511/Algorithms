class Solution {
public:
    
    void dfs(vector<int>v[],int ver,int visited[])
    {
        visited[ver]=1;
        for(int i=0;i<v[ver].size();i++)
        {
            if(visited[v[ver][i]]==0)
                dfs(v,v[ver][i],visited);
        }
    }

    int NoOfConnectedComponents(vector<int>v[],int i,int noofvertices)
    {
        int visited[noofvertices],noofconnectedcomp=0,level=0;
        memset(visited,0,sizeof(visited));
        for(int i=0;i<noofvertices;i++)
        {
            if(visited[i]==0)
            {
                dfs(v,i,visited);
                noofconnectedcomp++;
            }
        }
        return noofconnectedcomp;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>v[n];
        int m=connections.size();
        if(m<n-1)
            return -1;
        for(int i=0;i<m;i++)
        {
            v[connections[i][0]].push_back(connections[i][1]);
            v[connections[i][1]].push_back(connections[i][0]);
        }
        return NoOfConnectedComponents(v,0,n)-1;
    }
};