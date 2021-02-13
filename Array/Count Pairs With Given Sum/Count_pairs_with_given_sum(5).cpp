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
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin >> arr[i];
	    long long ans=0;
	    for(int i=0;i<n-1;i++)
	    {
	        for(int j=i+1;j<n;j++)
	        {
	            if(arr[j]+arr[i]==k)
	                ans++;
	        }
	    }
	    cout << ans << '\n';
	}
	return 0;
}