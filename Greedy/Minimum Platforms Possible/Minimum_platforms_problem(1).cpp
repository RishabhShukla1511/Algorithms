// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


int findPlatform(int arr[], int dep[], int n)
{
	// Your code here
	vector<pair<int,int>>v;
	for(int i=0;i<n;i++)
	    v.push_back({arr[i],dep[i]});
	sort(v.begin(),v.end());
	vector<int>platforms;
	platforms.push_back(v[0].second);
	for(int i=1;i<n;i++)
	{
	    int s=platforms.size(),j;
	    for(j=0;j<s;j++)
	    {
	        if(platforms[j]<v[i].first)
	            break;
	    }
	    if(j==s)
	        platforms.push_back(v[i].second);
	    else
	        platforms[j]=v[i].second;
	}
	return platforms.size();
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