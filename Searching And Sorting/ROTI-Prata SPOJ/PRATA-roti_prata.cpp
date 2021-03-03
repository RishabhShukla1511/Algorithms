#include<bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

int calc(int t,map<int,int>m,vector<int>v[])
{
    int tot=0;
    for(auto it:m)
    {
        int val=it.first;
        int pos=upper_bound(v[val].begin(),v[val].end(),t)-v[val].begin();
        tot+=pos*it.second;
    }
    return tot;
}

int find(map<int,int>m,vector<int>v[],int p)
{
    int l=0,h=4004000;
    while(l<h)
    {
        int mid=(l+h)/2,val=calc(mid,m,v);
        if(val<p)
            l=mid+1;
        else
            h=mid;
    }
    return l;
}

int main()
{
    fastIO();
    vector<int>v[9];
    for(int i=1;i<=8;i++)
    {
        int val=0;
        for(int j=1;val<=4004000;j++)
        {
            val+=j*i;
            v[i].push_back(val);
        }
    }
    int t;
    cin >> t;
    while(t--)
    {
        map<int,int>m;
        int p,l;
        cin >> p >> l;
        for(int i=1;i<=l;i++)
        {
            int a;
            cin >> a;
            m[a]++;
        }
        cout << find(m,v,p) << '\n';
    }
}