// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

bool custom_sort(pair<int,char>a,pair<int,char>b)
{
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}

int findPlatform(int arr[], int dep[], int n)
{
	// Your code here
	vector<pair<int,char>>v;
	for(int i=0;i<n;i++)
	{
	    v.push_back({arr[i],'a'});
	    v.push_back({dep[i],'d'});
    }
	sort(v.begin(),v.end(),custom_sort);
    int ans=1,curr=0;
    for(int i=0;i<2*n;i++)
    {
        if(v[i].second=='a')
            curr++;
        else
            curr--;
        ans=max(ans,curr);
    }
    return ans;
}


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
    cout <<findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends