#include<bits/stdc++.h>
#define fastIO() do {ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); } while (0)
#define ll long long
using namespace std;

int findOptHt(int arr[],int n,int m)
{
    int l=0,h=arr[n-1]-1,ans=0;
    while(l<=h)
    {
        int mid=(l+h)/2;
        ll val=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>mid)
                val+=arr[i]-mid;
        }
        if(val>=m)
        {
            l=mid+1;
            ans=mid;
        }
        else
            h=mid-1;
    }
    return ans;
}

int main()
{
    fastIO();
    int n,m;
    cin >> n >> m;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    sort(arr,arr+n);
    cout << findOptHt(arr,n,m);
}