#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n,k;
	    cin >> n >> k;
	    int arr[n],freq[101]={0};
	    for(int i=0;i<n;i++)
	    {
	        cin >> arr[i];
	        freq[arr[i]]++;
	    }
	    long long ans=0;
	    for(int i=0;i<n;i++)
	    {
	        if(k-arr[i]>=1 && k-arr[i]<=100)
	        {
	            if(k-arr[i]==arr[i])
	                ans+=freq[k-arr[i]]-1;
	            else
	                ans+=freq[k-arr[i]];
	        }
	    }
	    cout << ans/2 << '\n';
	}
	return 0;
}