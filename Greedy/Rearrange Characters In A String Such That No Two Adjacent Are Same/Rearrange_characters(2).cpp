#include<bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
using namespace std;

int main()
{
    fastIO();
    int t;
    cin >> t;
    while(t--)
    {
        string a;
        cin >> a;
        unordered_map<char,int>m;
        for(int i=0;i<a.size();i++)
            m[a[i]]++;
        vector<int>v;
        for(auto it:m)
            v.push_back(it.second);
        sort(v.begin(),v.end());
        int ans=0,val=0;
        for(int i=1;i<v.size();i++)
        {
            if(i==v.size()-1)
                val=2*v[i-1];
            ans+=2*v[i-1];
            v[i]-=v[i-1];
        }
        if(v[v.size()-1]>0)
        {
            v[v.size()-1]--;
            val++;
            ans++;
        }
        if(ans-val-1>=v[v.size()-1]-1)
            cout << "1\n";
        else
            cout << "0\n";
    }
}