//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        sort(arr,arr+n);
        int i=0,j=n-1,ans=0;
        while(i<j)
        {
            int sum=arr[i]+arr[j];
            if(sum>k)
                j--;
            else if(sum<k)
                i++;
            else
            {
                int x=arr[i],y=arr[j],xx=i,yy=j;
                while(i<j && arr[i]==x)
                    i++;
                while(j>=i && arr[j]==y)
                    j--;
                if(x==y)
                {
                    int temp=i-xx+yy-j;
                    ans+=(temp*(temp-1))/2;
                }
                else
                    ans+=(i-xx)*(yy-j);
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
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}  // } Driver Code Ends