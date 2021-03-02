#include<bits/stdc++.h>
#define ll long long
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;
struct custom_hash {static uint64_t splitmix64(uint64_t x) {x += 0x9e3779b97f4a7c15;x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;x = (x ^ (x >> 27)) * 0x94d049bb133111eb;return x ^ (x >> 31);}
size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x + FIXED_RANDOM);}};

int main()
{
    fastIO();
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        vector<ll>v(n);
        for(ll i=0;i<n;i++)
            cin >> v[i];
        ll cnt=0,sum=0;
        unordered_map<ll,ll,custom_hash>m;
        for(ll i=0;i<n;i++)
        {
            sum+=v[i];
            if(sum==0)
                cnt++;
            if(m[sum]!=0)
                cnt+=m[sum];
            m[sum]++;
        }
        v.clear();
        cout << cnt << '\n';
    }
}