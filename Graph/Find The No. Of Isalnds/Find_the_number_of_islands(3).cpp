#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={-1,0,1,-1,1,-1,0,1};

    bool isSafe(vector<vector<char>>& grid,vector<vector<int>>& visited,int x,int y)
    {
        int n=grid.size(),m=grid[0].size();
        return (x>=0 && x<n && y>=0 && y<m && visited[x][y]==0 && grid[x][y]=='1'); 
    }

    void dfs(vector<vector<char>>& grid,vector<vector<int>>& visited,int x,int y,int cnt)
    {
        if(!isSafe(grid,visited,x,y))
            return;
        visited[x][y]=1;
        for(int i=0;i<8;i++)
            dfs(grid,visited,x+dx[i],y+dy[i],cnt);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size(),cnt=1;
        vector<vector<int>>visited;
        vector<int>temp(m);
        fill(temp.begin(),temp.end(),0);
        for(int i=0;i<n;i++)
            visited.push_back(temp);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j]=='1')
                {
                    dfs(grid,visited,i,j,cnt);
                    cnt++;
                }
            }
        }
        return cnt-1;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends