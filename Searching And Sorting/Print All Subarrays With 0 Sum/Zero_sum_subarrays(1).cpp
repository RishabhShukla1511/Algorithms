//Initial function template for C++

#include<bits/stdc++.h>

using namespace std;

#define ll long long 
ll findSubarray(vector<ll> , int );

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        
        cout << findSubarray(arr,n) << "\n";
    }
	return 0;
}// } Driver Code Ends

struct custom_hash {static uint64_t splitmix64(uint64_t x) {x += 0x9e3779b97f4a7c15;x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;x = (x ^ (x >> 27)) * 0x94d049bb133111eb;return x ^ (x >> 31);}
size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x + FIXED_RANDOM);}};
//User function template for C++

// arr : given array 
// n : size of the given array
ll findSubarray(vector<ll> arr, int n ) {
    //code here
    ll sum=0,ans=0;
    unordered_map<ll,ll,custom_hash>m;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(sum==0)
            ans++;
        ans+=m[sum];
        m[sum]++;
    }
    return ans;
}
