#include<bits/stdc++.h>
using namespace std;

string SCS(string str1,string str2)
{
    int n=str1.length(),m=str2.length();
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(str1[i-1]==str2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    string scs="";
    int x=n,y=m;
    while(x>0 && y>0)
    {
        if(str1[x-1]==str2[y-1])
        {
            scs+=str1[x-1];
            x--;
            y--;
        }
        else
        {
            if(dp[x-1][y]>dp[x][y-1])
            {
                scs+=str1[x-1];
                x--;
            }
            else
            {
                scs+=str2[y-1];
                y--;
            }
        }
    }
    while(x--)
        scs+=str1[x];
    while(y--)
        scs+=str2[y];
    reverse(scs.begin(),scs.end());
    return scs;
}

int main()
{
    string str1,str2;
    cout << "Enter the first string\n";
    cin >> str1;
    cout << "Enter the second string\n";
    cin >> str2;
    cout << "Shortest Common Supersequence of " << str1 << " and " << str2 << " is: " << SCS(str1,str2);
}