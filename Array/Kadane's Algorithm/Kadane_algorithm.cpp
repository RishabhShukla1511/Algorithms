#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find subarray with maximum sum
// arr: input array
// n: size of array

bool negarr(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
            return false;
    }
    return true;
}

int get_max(int arr[],int n)
{
    int max=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max)
            max=arr[i];
    }
    return max;
}

int maxSubarraySum(int arr[], int n){
    
    // Your code here
    int maxsum=0,maxtill=0;
    if(negarr(arr,n))
        return get_max(arr,n);
    for(int i=0;i<n;i++)
    {
        if(maxtill<0)
            maxtill=0;
        else
            maxtill+=arr[i];
        if(maxtill<0)
            maxtill=0;
        maxsum=max(maxtill,maxsum);
    }
    return maxsum;
}

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        cout << maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends