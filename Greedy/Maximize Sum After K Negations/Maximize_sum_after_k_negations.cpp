#include<bits/stdc++.h>
#define ll long long
using namespace std;

long long int maximizeSum(long long int a[], int n, int k);

int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         
         cout<<maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}// } Driver Code Ends




long long int maximizeSum(long long int a[], int n, int k)
{
    // Your code goes here
    long long int sum=0;
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        if(a[i]<0)
        {
            if(k>0)
            {
                a[i]=-a[i];
                sum+=a[i];
                k--;
            }
            else
                sum+=a[i];
        }
        else
            sum+=a[i];
    }
    sort(a,a+n);
    if(k%2)
        sum+=-2*a[0];
    return sum;
}