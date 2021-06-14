#include<bits/stdc++.h>
using namespace std;

bool Sequence_pattern_match(string str1,string str2)
{
    int n=str1.length(),m=str2.length(),dp[n+1][m+1];
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
    return dp[n][m]==str1.length();
}

int main()
{
    string str1,str2;
    cout << "Enter the first string\n";
    cin >> str1;
    cout << "Enter the second string\n";
    cin >> str2;
    if(Sequence_pattern_match(str1,str2))
        cout << "Yes, " << str1 << " is a subsequence of " << str2;
    else    
        cout << "No, " << str1 << " is not a subsequence of " << str2;
}