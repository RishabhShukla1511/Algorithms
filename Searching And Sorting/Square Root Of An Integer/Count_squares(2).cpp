
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution {
  public:
  
    long long findSqrt(long long n,long long l,long long h,long long ans)
    {
        if(l<=h)
        {
            long long mid=l+(h-l)/2;
            if(mid*mid==n)
                return mid;
            else if(mid*mid<n)
                return findSqrt(n,mid+1,h,mid);
            else
                return findSqrt(n,l,mid-1,ans);
        }
        return ans;
    }
    
    int countSquares(int N) {
        // code here
        long long ans=findSqrt(N,1,N/2,ans);
        if(ans*ans==N)
            return ans-1;
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}  // } Driver Code Ends