
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends





class Solution
{
	public:
	
	    int edist(string s,string t,int m,int n,vector<vector<int>>&v)
	    {
	        if(v[m][n]!=-1)
	            return v[m][n];
	        if(m==0)
	        {
	            v[m][n]=n;
	            return n;
	        }
	        if(n==0)
	        {
	            v[m][n]=m;
	            return m;
	        }
	        if(s[m-1]==t[n-1])
	        {
	            v[m][n]=edist(s,t,m-1,n-1,v);
	            return v[m][n];
	        }
	        v[m][n]=1+min(edist(s,t,m-1,n,v),min(edist(s,t,m,n-1,v),edist(s,t,m-1,n-1,v)));
	        return v[m][n];
	    }
	
		int editDistance(string s, string t)
		{
		    // Code here
		    vector<vector<int>>v;
		    for(int i=0;i<=s.size();i++)
		    {
		        vector<int>a;
		        for(int j=0;j<=t.size();j++)
		            a.push_back(-1);
		        v.push_back(a);
		    }
		    return edist(s,t,s.size(),t.size(),v);
		}
};


// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	int ans = ob.editDistance(s, t);
    	cout << ans <<"\n";
    }
	return 0;
}
  // } Driver Code Ends