// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int dp[205][205][2];

    int boolParenthesizationUtil(string expr,int i,int j,bool isTrue)
    {
        if(i>j) 
            return 0;
        
        if(dp[i][j][isTrue]!=-1) 
            return dp[i][j][isTrue];
            
        if(i==j)
        {
            if(isTrue)
                return expr[i]=='T';
            else
                return expr[i]=='F';
        }
        
        int ways=0;
        for(int k=i+1;k<j;k+=2)
        {
            if(dp[i][k-1][1]==-1)
                dp[i][k-1][1]=boolParenthesizationUtil(expr,i,k-1,true);
            if(dp[i][k-1][0]==-1)
                dp[i][k-1][0]=boolParenthesizationUtil(expr,i,k-1,false);
            if(dp[k+1][j][1]==-1)
                dp[k+1][j][1]=boolParenthesizationUtil(expr,k+1,j,true);
            if(dp[k+1][j][0]==-1)
                dp[k+1][j][0]=boolParenthesizationUtil(expr,k+1,j,false);
            if(expr[k]=='&')
            {
                if(isTrue)
                    ways+=(
                        dp[i][k-1][1]*dp[k+1][j][1]
                        )%1003;
                else
                    ways+=(
                        (dp[i][k-1][1]*dp[k+1][j][0])%1003+
                        (dp[k+1][j][1]*dp[i][k-1][0])%1003+
                        (dp[i][k-1][0]*dp[k+1][j][0])%1003
                        )%1003;
            }
            else if(expr[k]=='|')
            {
                if(isTrue)
                    ways+=(
                        (dp[i][k-1][1]*dp[k+1][j][0])%1003+
                        (dp[k+1][j][1]*dp[i][k-1][0])%1003+
                        (dp[i][k-1][1]*dp[k+1][j][1])%1003
                        )%1003;
                else
                    ways+=(
                        dp[i][k-1][0]*dp[k+1][j][0]
                        )%1003;
            }
            else
            {
                if(isTrue)
                    ways+=(
                        (dp[i][k-1][1]*dp[k+1][j][0])%1003+
                        (dp[k+1][j][1]*dp[i][k-1][0])%1003
                        )%1003;
                else
                    ways+=(
                        (dp[i][k-1][1]*dp[k+1][j][1])%1003+
                        (dp[i][k-1][0]*dp[k+1][j][0])%1003
                        )%1003;
            }
        }
        return ways%1003;
    }

    int countWays(int N, string S){
        // code here
        memset(dp,-1,sizeof(dp));
        return boolParenthesizationUtil(S,0,N-1,true);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends