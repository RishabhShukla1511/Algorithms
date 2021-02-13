//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        int freq[1000001]={0};
        for(int i=0;i<n;i++)
            freq[arr[i]]++;
        long sum=0;
        for(int i=1;i<=1000000;i++)
        {
            if(freq[i]>0)
            {
                if(i==k-i)
                    sum+=(freq[i]*(freq[i]-1))/2;
                else if(k-i>0 && k-i<=1000000 && freq[k-i])
                {
                    sum+=freq[i]*freq[k-i];
                    freq[k-i]=0;
                }
                freq[i]=0;
            }
        }
        return sum;
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