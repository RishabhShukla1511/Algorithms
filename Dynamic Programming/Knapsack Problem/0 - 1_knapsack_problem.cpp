#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    
    int maxValue(int W, int wt[], int val[], int n,vector<vector<int>>&v) 
    { 
        // Your code here
        if(v[W][n]!=-1)
            return v[W][n];
        if(wt[n-1]>W)
        {
            v[W][n]=maxValue(W,wt,val,n-1,v);
            return v[W][n];
        }
        v[W][n]=max(maxValue(W,wt,val,n-1,v),maxValue(W-wt[n-1],wt,val,n-1,v)+val[n-1]);
        return v[W][n];
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        // Your code here
        vector<vector<int>>v;
        vector<int>temp(n+1,-1);
        for(int i=0;i<=W;i++)
            v.push_back(temp);
        for(int i=0;i<=W;i++)
            v[i][0]=0;
        for(int i=0;i<=n;i++)
            v[0][i]=0;
        return maxValue(W,wt,val,n,v);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends