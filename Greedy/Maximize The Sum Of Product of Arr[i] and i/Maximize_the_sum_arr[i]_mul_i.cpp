#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

int Maximize(int a[],int n);

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        cout<<Maximize(a,n)<<endl;
    }
}// } Driver Code Ends


int Maximize(int a[],int n)
{
    // Complete the function
    int mod=1000000007;
    sort(a,a+n);
    long long int sum=0;
    for(int i=0;i<n;i++)
    {
        long long int f=a[i]%mod,s=i%mod;
        f*=s;
        f%=mod;
        sum+=f;
        sum%=mod;
    }
    return sum;
}
