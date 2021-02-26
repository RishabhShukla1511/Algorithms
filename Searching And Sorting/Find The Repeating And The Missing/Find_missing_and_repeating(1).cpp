#include<bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin >> t;
	int arr[1000001]={0};
	while(t--)
	{
	    int n;
	    cin >> n;
	    for(int i=0;i<n;i++)
	    {
	        int a;
	        cin >> a;
	        arr[a]++;
	    }
	    int d=0,m=0;
	    for(int i=1;i<=1000000;i++)
	    {
	        if(arr[i]==2 && d==0)
	            d=i;
	        if(arr[i]==0 && m==0)
	            m=i;
	        if(d!=0 && m!=0)
	            break;
	    }
	    cout << d << " " << m << '\n';
	    for(int i=1;i<=1000000;i++)
	        arr[i]=0;
	}
	return 0;
}