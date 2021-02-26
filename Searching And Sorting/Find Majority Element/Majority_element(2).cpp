#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find majority element in the array
// a: input array
// size: size of input array
int majorityElement(int a[], int n)
{
    // your code here
    sort(a,a+n);
    int cnt=0,val=a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]==val)
            cnt++;
        else
        {
            val=a[i];
            cnt=1;
        }
        if(cnt>n/2)
            return val;
    }
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