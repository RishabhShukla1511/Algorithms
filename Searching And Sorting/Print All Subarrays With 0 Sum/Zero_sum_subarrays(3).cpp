#include<bits/stdc++.h>
#define ll long long
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

int main()
{
    fastIO();
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll arr[n];
        for(ll i=0;i<n;i++)
            cin >> arr[i];
        ll cnt=0,sum=0;
        map<ll,ll>m;
        for(ll i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum==0)
                cnt++;
            if(m[sum]!=0)
                cnt+=m[sum];
            m[sum]++;
        }
        cout << cnt << '\n';
    }
}