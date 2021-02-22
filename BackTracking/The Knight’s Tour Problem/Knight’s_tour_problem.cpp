#include<bits/stdc++.h>
#define n 8
using namespace std;

int dx[]={2,1,-1,-2,-2,-1,1,2};
int dy[]={1,2,2,1,-1,-2,-2,-1};

bool isSafe(int x,int y,int board[n][n])
{
    return (x>=0 && y>=0 && x<n && y<n && board[x][y]==0);
}

bool isAvailable(int board[n][n],int x,int y,int cnt)
{
    if(!isSafe(x,y,board))   
        return false;
    board[x][y]=cnt;
    if(cnt==n*n)
        return true;
    for(int i=0;i<8;i++)
    {
        if(isAvailable(board,x+dx[i],y+dy[i],cnt+1))
            return true;
    }
    board[x][y]=0;
    return false;
}

int main()
{
    int board[n][n];
    memset(board,0,sizeof(board));
    if(!isAvailable(board,0,0,1))
        cout << "Solution does not exist\n";
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout << setw(2) << board[i][j] << " ";
            cout << '\n';
        }
    }
}