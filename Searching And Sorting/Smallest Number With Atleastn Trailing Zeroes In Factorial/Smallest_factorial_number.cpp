#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends




class Solution
{
    public:
    
        bool check(int p,int n)
        {
            int f=5,cnt=0;
            while(f<=p)
            {
                cnt+=p/f;
                f=f*5;
            }
            return (cnt>=n);
        }
    
        int findNum(int n)
        {
            //complete the function here
            int low=0,high=5*n;
            while(low<high)
            {
                int mid=(low+high)/2;
                if(check(mid,n))
                    high=mid;
                else
                    low=mid+1;
            }
            return low;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends