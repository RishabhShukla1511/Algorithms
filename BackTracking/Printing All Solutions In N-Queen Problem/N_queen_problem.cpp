#include<bits/stdc++.h>
using namespace std;

int cnt=0;

void print(vector<vector<int>>&board)
{
    int n=board.size();
    cout << ++cnt << ":\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(board[i][j]==-1)
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << '\n';
    }
    cout << '\n';
}

void fill(vector<vector<int>>&board,int x,int y)
{
    int n=board.size();
    for(int i=0;i<n;i++)
    {
        board[i][y]++;
        board[x][i]++;
    }
    int i=x,j=y;
    while(i>=0 && j>=0)
    {
        board[i][j]++;
        i--;
        j--;
    }
    i=x,j=y;
    while(i<n && j<n)
    {
        board[i][j]++;
        i++;
        j++;
    }
    i=x,j=y;
    while(i>=0 && j<n)
    {
        board[i][j]++;
        i--;
        j++;
    }
    i=x,j=y;
    while(i<n && j>=0)
    {
        board[i][j]++;
        i++;
        j--;
    }
    board[x][y]=-1;
}

void unfill(vector<vector<int>>&board,int x,int y)
{
    int n=board.size();
    for(int i=0;i<n;i++)
    {
        board[i][y]--;
        board[x][i]--;
    }
    int i=x,j=y;
    while(i>=0 && j>=0)
    {
        board[i][j]--;
        i--;
        j--;
    }
    i=x,j=y;
    while(i<n && j<n)
    {
        board[i][j]--;
        i++;
        j++;
    }
    i=x,j=y;
    while(i>=0 && j<n)
    {
        board[i][j]--;
        i--;
        j++;
    }
    i=x,j=y;
    while(i<n && j>=0)
    {
        board[i][j]--;
        i++;
        j--;
    }
    board[x][y]=0;
}

void find(vector<vector<int>>&board,int c,int k)
{
    int n=board.size();
    if(k==0)
    {
        print(board);
        return;
    }
    if(c>=n)
        return;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(board[i][c]==0)
        {
            fill(board,i,c);
            find(board,c+1,k-1);
            unfill(board,i,c);
            cnt++;
        }
    }
    if(cnt==0)
        return;
}

int main()
{
    cout << "N Queen Problem - Place N Queens in N*N Chessboard Without any Clashes - Using Backtracking\nIn each position 0 shows an empty position and 1 shows a filled position\n\n";
    int n;
    cout << "Enter the value of N\n";
    cin >> n;
    vector<vector<int>>board;
    vector<int>temp;
    for(int i=0;i<n;i++)
        temp.push_back(0);
    for(int i=0;i<n;i++)
        board.push_back(temp);
    for(int i=0;i<n;i++)
    {
        fill(board,i,0);
        find(board,1,n-1);
        unfill(board,i,0);
    }
    if(cnt==0)
        cout << "Solution does not exist\n";
}