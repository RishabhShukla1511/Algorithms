#include<bits/stdc++.h>

 // } Driver Code Ends


// Function to find majority element in the array
// a: input array
// size: size of input array

int findCandidate(int a[],int n)
{
    int ind=0,cnt=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]==a[ind])
            cnt++;
        else
            cnt--;
        if(cnt==0)
        {
            cnt=1;
            ind=i;
        }
    }
    return a[ind];
}

bool check(int a[],int n,int val)
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==val)
            cnt++;
    }
    if(cnt>n/2)
        return true;
    return false;
}

int majorityElement(int a[], int n)
{
    // your code here
    int cand=findCandidate(a,n);
    if(check(a,n,cand))
        return cand;
    else
        return -1;
}

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        cout << majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends