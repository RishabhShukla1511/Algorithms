
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int mod=1000000007;
    
    int ncr(int n,int r,vector<vector<long long>>&v)
    {
        if(v[n][r]!=-1)
            return v[n][r];
        v[n][r]=(ncr(n-1,r,v)%mod+ncr(n-1,r-1,v)%mod)%mod;
        return v[n][r];
    }
    
    int nCr(int n, int r){
        // code here
        if(n<r)
            return 0;
        vector<vector<long long>>v;
        vector<long long>temp(r+1,-1);
        for(int i=0;i<=n;i++)
            v.push_back(temp);
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=r;j++)
            {
                if(i==0 || i<j)
                    v[i][j]=0;
                if(j==0 || i==j)
                    v[i][j]=1;
            }
        }
        return ncr(n,r,v);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends