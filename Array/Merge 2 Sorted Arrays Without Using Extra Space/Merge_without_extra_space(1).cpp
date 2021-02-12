#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int n,m;
	    cin >> n >> m;
	    int arr[n+m];
	    for(int i=0;i<n;i++)
	        cin >> arr[i];
	    for(int i=n;i<n+m;i++)
	        cin >> arr[i];
	    sort(arr,arr+n+m);
	    for(int i=0;i<n+m;i++)
	        cout << arr[i] << " ";
	    cout << '\n';
	}
	return 0;
}