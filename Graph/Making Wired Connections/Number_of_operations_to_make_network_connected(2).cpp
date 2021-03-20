class Solution {
public:
    
    void dfs(vector<int>v[],int vis[],int ver)
    {
        vis[ver]=1;
        for(int i=0;i<v[ver].size();i++)
        {
            if(!vis[v[ver][i]])
                dfs(v,vis,v[ver][i]);
        }
        return;
    }
    
    int noc(vector<int>v[],int n)
    {
        int vis[n],ans=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(v,vis,i);
                ans++;
            }
        }
        return ans;
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
        return noc(v,n)-1;
    }
};