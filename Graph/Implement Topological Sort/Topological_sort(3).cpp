#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	
	void topo(int ver,vector<int>adj[],vector<int>&visited,vector<int>&toposort)
	{
	    visited[ver]=1;
	    for(int i=0;i<adj[ver].size();i++)
	    {
	        if(!visited[adj[ver][i]])
	            topo(adj[ver][i],adj,visited,toposort);
	    }
	    toposort.push_back(ver);
	    return;
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) {
	    // code here
	    vector<int>toposort,visited(V);
	    fill(visited.begin(),visited.end(),0);
	    for(int i=0;i<V;i++)
	    {
	        if(!visited[i])
	            topo(i,adj,visited,toposort);
	    }
	    reverse(toposort.begin(),toposort.end());
	    return toposort;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends