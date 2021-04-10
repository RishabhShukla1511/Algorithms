#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

	bool isCycle(int V, vector<int>adj[]){
	    // Code here
	    bool visited[V];
	    for(int i=0;i<V;i++)
	        visited[i]=false;
	    visited[0]=true;
	    queue<pair<int,int>>q;
	    q.push({0,-1});
	    while(!q.empty())
	    {
	        int n=q.size();
	        for(int i=1;i<=n;i++)
	        {
	            int ver=q.front().first,par=q.front().second;
	            q.pop();
                for(int j=0;j<adj[ver].size();j++)
                {
                    if(adj[ver][j]==ver)
                        return true;
                    if(!visited[adj[ver][j]])
                    {
                        q.push({adj[ver][j],ver});
                        visited[adj[ver][j]]=true;
                    }
                    else
                    {
                        if(adj[ver][j]!=par)
                            return true;
                    }
                }
	        }
	    }
        return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends