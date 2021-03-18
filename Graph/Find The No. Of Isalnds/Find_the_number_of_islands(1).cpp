#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={-1,0,1,-1,1,-1,0,1};

    void dfs(int x,int y,vector<vector<char>>& grid,vector<vector<int>>& visited)
    {
        int n=grid.size(),m=grid[0].size();
        visited[x][y]=1;
        for(int i=0;i<8;i++)
        {
            int posx=x+dx[i],posy=y+dy[i];
            if(posx>=0 && posx<n && posy>=0 && posy<m && grid[posx][posy]=='1' && !visited[posx][posy])
                dfs(posx,posy,grid,visited);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size(),cnt=0;
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
                    dfs(i,j,grid,visited);
                    cnt++;
                }
            }
        }
        return cnt;
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