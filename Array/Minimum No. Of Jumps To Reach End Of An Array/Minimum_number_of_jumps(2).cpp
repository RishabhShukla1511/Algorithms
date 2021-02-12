#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends









// Function to return minimum number of jumps to end of array
int minJumps(int arr[], int n){
    // Your code here
    if(arr[0]==0)
        return -1;
    int maxreach=arr[0],step=arr[0],jump=1;
    for(int i=1;i<n;i++)
    {
        if(i==n-1)
            return jump;
        maxreach=max(maxreach,i+arr[i]);
        step--;
        if(step==0)
        {
            jump++;
            if(i>=maxreach)
                return -1;
            step=maxreach-i;
        }
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