#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends






class Solution{
    public:
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        vector<vector<int>>v(32);
        for(int i=0;i<n;i++)
        {
            int count=__builtin_popcount(arr[i]);
            v[count].push_back(arr[i]);
        }
        int pos=0;
        for(int i=31;i>=0;i--)
        {
            for(int j=0;j<v[i].size();j++)
                arr[pos++]=v[i][j];
        }
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends