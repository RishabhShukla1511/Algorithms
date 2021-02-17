#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int max=0,ans=-1;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i].back()!=0)
	        {
    	        auto it=lower_bound(arr[i].begin(),arr[i].end(),1);
    	        if(it!=arr[i].end() && m-(it-arr[i].begin())>max)
    	        {
    	            max=m-(it-arr[i].begin());
    	            ans=i;
    	        }
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends