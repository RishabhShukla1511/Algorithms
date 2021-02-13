#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

// Function to find inversion count in the array

// arr[]: Input Array
// N : Size of the Array arr[]

long long getSum(int BITree[],int index)
{
    long long sum=0;
    while(index>0)
    {
        sum+=BITree[index];
        index-=index&(-index);
    }
    return sum;
}

void update(int BITree[],int n,int index,int val)
{
    while(index<=n)
    {
        BITree[index]+=val;
        index+=index&(-index);
    }
}

long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    int maxval=arr[0];
    for(int i=1;i<N;i++)
    {
        if(arr[i]>maxval)
            maxval=arr[i];
    }
    long long invcount=0;
    int BITree[maxval+1]={0};
    for(int i=N-1;i>=0;i--)
    {
        invcount+=getSum(BITree,arr[i]-1);
        update(BITree,maxval,arr[i],1);
    }
    return invcount;
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