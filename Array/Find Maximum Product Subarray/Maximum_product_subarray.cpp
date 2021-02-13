#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


//User function template for C++
class Solution{
public:

    long long max(long long a,long long b){
        if(a>b) 
            return a;
        return b;
    }
    long long min(long long a,long long b){
        if(a<b) 
            return a;
        return b;
    }

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
	    // code here
	    long long maxi=1,mini=1,ans=0;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]>0)
	        {
	            maxi=max(maxi*arr[i],1);
	            mini=min(mini*arr[i],1);
	        }
	        else if(arr[i]<0)
	        {
	            long long a=maxi,b=mini;
	            maxi=max(b*arr[i],1);
	            mini=a*arr[i];
	        }
	        else
	        {
	            maxi=1;
	            mini=1;
	        }
	        ans=max(ans,maxi);
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends