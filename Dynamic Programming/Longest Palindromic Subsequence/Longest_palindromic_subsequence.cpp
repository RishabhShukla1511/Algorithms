#include<bits/stdc++.h>
using namespace std;

string LCS(string str1,string str2)
{
    int n=str1.length();
    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(str1[i-1]==str2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    string lps="";
    int x=n,y=n;
    while(x>0 && y>0)
    {
        if(str1[x-1]==str2[y-1])
        {
            lps+=str1[x-1];
            x--;
            y--;
        }
        else
        {
            if(dp[x-1][y]>dp[x][y-1])
                x--;
            else
                y--;   
        }        
    }
    return lps;
}

string LPS(string str)
{
    string org=str;
    reverse(str.begin(),str.end());
    return LCS(org,str);
}

int main()
{
    string str;
    cout << "Enter the string\n";
    cin >> str;
    cout << "Longest paindromic subsequence in " << str << " is " << LPS(str);
}