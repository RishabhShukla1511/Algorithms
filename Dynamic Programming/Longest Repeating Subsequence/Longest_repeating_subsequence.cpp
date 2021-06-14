#include<bits/stdc++.h>
using namespace std;

int LRS(string str)
{
    int n=str.length(),dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j && str[i-1]==str[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][n];
}

int main()
{
    string str;
    cout << "Enter the string\n";
    cin >> str;
    cout << "Length of the longest repeating subsequence in " << str << " is " << LRS(str);
}