#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	
	vector<vector<int>>nearest(vector<vector<int>>grid){
	    // Code here
	    int n=grid.size(),m=grid[0].size(),dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
	    vector<vector<int>>dist;
	    queue<pair<int,int>>q;
	    for(int i=0;i<n;i++)
	    {
	        vector<int>temp(m);
	        fill(temp.begin(),temp.end(),INT_MAX);
	        dist.push_back(temp);
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1)
	            {
	                q.push({i,j});
	                dist[i][j]=0;
	            }
	        }
	    }
	    int d=1;
	    while(!q.empty())
	    {
	        int qs=q.size();
	        for(int i=1;i<=qs;i++)
	        {
	            pair<int,int>pos=q.front();
	            q.pop();
	            int x=pos.first,y=pos.second;
	            for(int i=0;i<4;i++)
	            {
	                int xx=x+dx[i],yy=y+dy[i];
	                if(xx>=0 && xx<n && yy>=0 && yy<m && grid[xx][yy]==0)
	                {
	                    dist[xx][yy]=d;
	                    q.push({xx,yy});
	                    grid[xx][yy]=1;
	                }
	            }
	        }
	        d++;
	    }
	    return dist;
	}
};
// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends