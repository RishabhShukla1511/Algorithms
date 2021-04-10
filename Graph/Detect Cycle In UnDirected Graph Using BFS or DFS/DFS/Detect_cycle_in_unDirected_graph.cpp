#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    bool dfs(vector<int>adj[],bool visited[],int ver,int prev)
    {
        visited[ver]=true;
        for(int i=0;i<adj[ver].size();i++)
        {
            if(!visited[adj[ver][i]])
            {
                if(dfs(adj,visited,adj[ver][i],ver))
                    return true;
            }
            else
            {
                if(adj[ver][i]!=prev)
                    return true;
            }
        }
        return false;
    }

	bool isCycle(int V, vector<int>adj[]){
	    // Code here
	    bool visited[V];
	    for(int i=0;i<V;i++)
	        visited[i]=false;
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i] && dfs(adj,visited,i,-1))
	            return true;
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