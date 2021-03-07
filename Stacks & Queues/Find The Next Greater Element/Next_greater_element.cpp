#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        ll arr[n];
        for(int i=0;i<n;i++)
            cin >> arr[i];
        stack<ll>s;
        ll ans[n];
        for(int i=0;i<n;i++)
        {
            if(s.size()==0)
                s.push(i);
            else
            {
                while(s.size()!=0 && arr[s.top()]<arr[i])
                {
                    ans[s.top()]=arr[i];
                    s.pop();
                }
                s.push(i);
            }
        }
        while(s.size()!=0)
        {
            ans[s.top()]=-1;
            s.pop();
        }
        for(int i=0;i<n;i++)
            cout << ans[i] << " ";
        cout << '\n';
    }
}