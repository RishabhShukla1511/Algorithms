#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    bool isSafe(int x,int y,vector<vector<int>>&grid)
    {
        int n=grid.size(),m=grid[0].size();
        return (x>=0 && x<n && y<m && y>=0 && grid[x][y]==1);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size(),cnt=0,dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1)
                    cnt++;
            }
        }
        int timereq=0;
        while(cnt && !q.empty())
        {
            int n=q.size();
            for(int i=1;i<=n;i++)
            {
                pair<int,int>pos=q.front();
                q.pop();
                int x=pos.first,y=pos.second;
                for(int i=0;i<4;i++)
                {
                    if(isSafe(x+dx[i],y+dy[i],grid))
                    {
                        q.push({x+dx[i],y+dy[i]});
                        grid[x+dx[i]][y+dy[i]]=2;
                        cnt--;
                    }    
                }
            }
            timereq++;
        }
        if(cnt==0)
            return timereq;
        return -1;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends