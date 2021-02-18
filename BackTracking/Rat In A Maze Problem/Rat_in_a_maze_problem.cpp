// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

#define MAX 5
vector<string> findPath(int m[MAX][MAX], int n);

// Position this line where user code will be pasted.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

        vector<string> result = findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}// } Driver Code Ends

int visited[MAX][MAX];

bool isSafe(int x,int y,int n)
{
    return (x>=0 && x<n && y>=0 && y<n && visited[x][y]==0);
}

void traverse(string ans,int m[MAX][MAX],int x,int y,int n,vector<string>&possiblepaths)
{
    if(isSafe(x,y,n) && m[x][y]==1)
    {
        if(x==n-1 && y==n-1)
        {
            possiblepaths.push_back(ans);
            return;
        }
        visited[x][y]=1;
        traverse(ans+"U",m,x-1,y,n,possiblepaths);
        traverse(ans+"D",m,x+1,y,n,possiblepaths);
        traverse(ans+"L",m,x,y-1,n,possiblepaths);
        traverse(ans+"R",m,x,y+1,n,possiblepaths);
        visited[x][y]=0;
    }
}
// User function template for C++

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5
vector<string> findPath(int m[MAX][MAX], int n) {
    // Your code goes here
    vector<string>possiblepaths;
    memset(visited,0,sizeof visited);
    traverse("",m,0,0,n,possiblepaths);
    sort(possiblepaths.begin(),possiblepaths.end());
    return possiblepaths;
}
