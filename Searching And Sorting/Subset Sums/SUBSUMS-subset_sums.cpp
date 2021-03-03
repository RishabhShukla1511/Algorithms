#include<bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
#define ll long long
using namespace std;

ll findSum(ll arr[],string comb)
{
    ll n=comb.size(),sum=0;
    for(ll i=0;i<n;i++)
    {
        if(comb[i]=='1')
            sum+=arr[i];
    }
    return sum;
}

void findAllperm(ll arr[],string comb,ll pos,vector<ll>&v)
{
    int n=comb.size();
    if(pos==n)
    {
        ll sum=findSum(arr,comb);
        v.push_back(sum);   
        return;
    }
    comb[pos]='0';
    findAllperm(arr,comb,pos+1,v);
    comb[pos]='1';
    findAllperm(arr,comb,pos+1,v);
}

ll totalSubs(vector<ll>&a,vector<ll>&b,ll s1,ll s2)
{
    ll n=a.size(),ans=0;
    for(int i=0;i<n;i++)
    {
        ll pos1=lower_bound(b.begin(),b.end(),s1-a[i])-b.begin();
        ll pos2=upper_bound(b.begin(),b.end(),s2-a[i])-b.begin()-1;
        if(pos1<=pos2)
            ans+=pos2-pos1+1;
    }
    return ans;
}

int main()
{
    fastIO();
    ll n,a,b;
    cin >> n >> a >> b;
    ll arr[n];
    string firstp="",secondp="";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
        if(i<n/2)
            firstp+="0";
        else
            secondp+="0";
    }    
    vector<ll>firstsums,secondsums;
    findAllperm(arr,firstp,0,firstsums);
    findAllperm(arr+n/2,secondp,0,secondsums);
    sort(firstsums.begin(),firstsums.end());
    sort(secondsums.begin(),secondsums.end());
    cout << totalSubs(firstsums,secondsums,a,b);
}