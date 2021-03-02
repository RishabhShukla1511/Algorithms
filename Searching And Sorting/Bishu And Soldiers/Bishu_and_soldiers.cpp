#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
   	cout.tie(0);
	int n;
	cin >> n;
	int power[n],sum[n];
	for(int i=0;i<n;i++)
		cin >> power[i];
	sort(power,power+n);
	sum[0]=power[0];
	for(int i=1;i<n;i++)
		sum[i]=power[i]+sum[i-1];
	int q;
	cin >> q;
	while(q--)
	{
		int powofbishu;
		cin >> powofbishu;
		auto it=upper_bound(power,power+n,powofbishu);
		int pos=it-power-1;
		cout << pos+1 << " " << sum[pos] << '\n'; 
	}
}