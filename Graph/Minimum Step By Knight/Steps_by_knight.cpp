#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	    vector<vector<int>>visited;
	    vector<int>temp(N+1);
	    fill(temp.begin(),temp.end(),0);
	    for(int i=0;i<=N;i++)
	        visited.push_back(temp);
	    int dx[8] = { -2, -1, 1, 2, -2, -1, 1, 2 }; 
	    int dy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
	    queue<pair<pair<int,int>,int>>q;
	    q.push({{KnightPos[0],KnightPos[1]},0});
	    visited[KnightPos[0]][KnightPos[1]]=1;
	    while(!q.empty())
	    {
	        pair<pair<int,int>,int>p=q.front();
	        q.pop();
	        int x=p.first.first,y=p.first.second,d=p.second;
	        if(x==TargetPos[0] && y==TargetPos[1])
	            return p.second;
	        for(int i=0;i<8;i++)
	        {
	            int px=x+dx[i],py=y+dy[i];
	            if(px>=1 && px<=N && py>=1 && py<=N && !visited[px][py])
	            {
	                q.push({{px,py},d+1});
	                visited[px][py]=1;
	            }
	        }
	    }
	    return N;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends