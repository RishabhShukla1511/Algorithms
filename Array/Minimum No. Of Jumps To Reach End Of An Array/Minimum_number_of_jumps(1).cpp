#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends






// Function to return minimum number of jumps to end of array
int minJumps(int arr[], int n){
    // Your code here
    int sum=0,i=0;
    while(i<n)
    {
        if(i+arr[i]>=n-1)
            return sum+1;
        int ma=INT_MAX,pos=i;
        for(int j=i+1;j<=i+arr[i];j++)
        {
            if(n-(arr[j]+j+2)<ma)
            {
                ma=n-(arr[j]+j+2);
                pos=j;
            }
        }
        i=pos;
        sum++;
        if(ma==INT_MAX || arr[i]==0)
            break;
    }
    return -1;
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
            
        cout<<minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends