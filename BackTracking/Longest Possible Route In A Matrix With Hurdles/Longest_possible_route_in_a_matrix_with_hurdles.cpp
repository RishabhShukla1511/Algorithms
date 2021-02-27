#include<bits/stdc++.h>
using namespace std;

bool isSafe(int x,int y,vector<vector<int>>&v,vector<vector<int>>&visited)
{
    int n=v.size(),m=v[0].size();
    return (x>=0 && x<n && y>=0 && y<m && v[x][y]==1 && visited[x][y]==0);
}

void longestPath(int sx,int sy,int dx,int dy,int cnt,vector<vector<int>>&v,vector<vector<int>>&visited,int &ans)
{
    if(sx==dx && sy==dy)
    {
        ans=max(ans,cnt);
        return;
    }
    visited[sx][sy]=1;
    if(isSafe(sx-1,sy,v,visited))   
        longestPath(sx-1,sy,dx,dy,cnt+1,v,visited,ans);
    if(isSafe(sx,sy-1,v,visited))   
        longestPath(sx,sy-1,dx,dy,cnt+1,v,visited,ans);
    if(isSafe(sx+1,sy,v,visited))   
        longestPath(sx+1,sy,dx,dy,cnt+1,v,visited,ans);
    if(isSafe(sx,sy+1,v,visited))   
        longestPath(sx,sy+1,dx,dy,cnt+1,v,visited,ans);
    visited[sx][sy]=0;
    return;
}

int main()
{
    int n,m;
    cout << "Enter the number of rows of the matrix\n";
    cin >> m;
    cout << "Enter the number of columns of the matrix\n";
    cin >> n;
    vector<vector<int>>v,visited;
    int k=0;
    cout << "Enter the matrix where 0 denotes hurdles and 1 denotes freepath\n";
    for(int i=0;i<m;i++)
    {
        vector<int>temp,tempv;
        for(int j=0;j<n;j++)
        {
            int val;
            cin >> val;
            temp.push_back(val);
            if(val<0 || val>1)
            {
                k=1;
                break;
            }
            tempv.push_back(0);
        }
        if(k==1)
            break;
        v.push_back(temp);
        visited.push_back(tempv);
    }
    if(k==1)
        cout << "Invalid entry\n";
    else
    {
        int dx,dy;
        cout << "Enter the destination point\n";
        cin >> dx >> dy;
        if(dx<0 || dx>=m || dy<0 || dy>=n)
        {
            cout << "Invalid point\n";
            k=1;
        }
        if(k==0)
        {
            int ans=0;
            longestPath(0,0,dx,dy,0,v,visited,ans);
            cout << "Longest Possible Path's length is " << ans;
        }
    }
}