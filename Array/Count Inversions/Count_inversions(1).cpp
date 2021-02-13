#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

// Function to find inversion count in the array

// arr[]: Input Array
// N : Size of the Array arr[]

long long merge(long long arr[],long long temp[],long long l,long long mid,long long r)
{
    long long i=l,j=mid,k=l,invcount=0;
    while(i<mid && j<=r)
    {
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else
        {
            invcount+=mid-i;
            temp[k++]=arr[j++];
        }
    }
    while(i<mid)
    {
        temp[k++]=arr[i++];
    }
    while(j<=r)
    {
        temp[k++]=arr[j++];
    }
    for(int i=l;i<=r;i++)
        arr[i]=temp[i];
    return invcount;
}

long long mergeSort(long long arr[],long long temp[],long long l,long long r)
{
    long long inv_count=0;
    if(l<r)
    {
        long long mid=(l+r)/2;
        inv_count+=mergeSort(arr,temp,l,mid);
        inv_count+=mergeSort(arr,temp,mid+1,r);
        inv_count+=merge(arr,temp,l,mid+1,r);
    }
    return inv_count;
}

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    long long temp[N];
    return mergeSort(arr,temp,0,N-1);
}


// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        
        cout << inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends