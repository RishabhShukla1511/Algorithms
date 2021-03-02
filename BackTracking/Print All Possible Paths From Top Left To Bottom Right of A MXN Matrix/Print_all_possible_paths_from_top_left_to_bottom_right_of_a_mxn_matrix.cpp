#include<bits/stdc++.h>
using namespace std;

bool isSafe(int x,int y,int n,int m,vector<vector<int>>&visited)
{
    return (x>=0 && x<n && y>=0 && y<m && visited[x][y]==0);
}

void allPossiblePaths(int x,int y,vector<vector<int>>&matrix,vector<vector<int>>&visited,vector<vector<int>>&allpaths,vector<int>&path)
{
    int n=matrix.size(),m=matrix[0].size();
    if(x==n-1 && y==m-1)
    {
        path.push_back(matrix[x][y]);
        allpaths.push_back(path);
        path.pop_back();
        return;
    }
    visited[x][y]=1;
    path.push_back(matrix[x][y]);
    if(isSafe(x,y+1,n,m,visited))
        allPossiblePaths(x,y+1,matrix,visited,allpaths,path);
    if(isSafe(x+1,y,n,m,visited))
        allPossiblePaths(x+1,y,matrix,visited,allpaths,path);
    visited[x][y]=0;
    path.pop_back();
}

void print(vector<vector<int>>&paths)
{
    cout << "Following are all possible paths from top left to bottom right\n";
    int n=paths.size();
    for(int i=0;i<n;i++)
    {
        int m=paths[i].size();
        for(int j=0;j<m;j++)
            cout << paths[i][j] << " ";
        cout << '\n';
    }
}

int main()
{
    //Moves allowed are right or down only
    //Source is 0,0 - Top LeftMost Element
    //Destination is n-1,m-1 - Bottom RightMost Element
    int n,m;
    cout << "Enter the number of rows in the path matrix\n";
    cin >> n;
    cout << "Enter the number of columns in the path matrix\n";
    cin >> m;
    vector<vector<int>>matrix,visited,paths;
    cout << "Enter the path matrix\n";
    for(int i=0;i<n;i++)
    {
        vector<int>temp,temp1;
        for(int j=0;j<m;j++)
        {
            int val;
            cin >> val;
            temp.push_back(val);
            temp1.push_back(0);
        }
        matrix.push_back(temp);
        visited.push_back(temp1);
    }
    vector<int>path;
    allPossiblePaths(0,0,matrix,visited,paths,path);
    print(paths);
}