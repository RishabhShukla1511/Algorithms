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
	    int freq[100001]={0};
	    for(int i=0;i<n;i++)
	    {
	        int a;
	        cin >> a;
	        freq[a]++;
	    }
	    int k=0;
	    for(int i=0;i<m;i++)
	    {
	        int a;
	        cin >> a;
	        if(freq[a]==0)
	            k=1;
	    }
	    if(k==0)
	        cout << "Yes\n";
	    else
	        cout << "No\n";
	}
	return 0;
}