#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int *ans=new int[2];
        sort(arr,arr+n);
        long long sum=(n*(n+1))/2,sumarr=0;
        for(int i=0;i<n;i++)
            sumarr+=arr[i];
        for(int i=1;i<n;i++)
        {
            if(arr[i]==arr[i-1])
                ans[0]=arr[i];
        }
        int i=1,k=0;
        for(int j=0;j<n;j++)
        {
            if(arr[j]==i)
                i++;
            else if(k==0)
                k=1;
            else
                break;
        }
        ans[1]=i;
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends