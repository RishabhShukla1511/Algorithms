#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,x;
        cin >> n >> x;
        int arr[n];
        for(int i=0;i<n;i++)
            cin >> arr[i];
        int i=0,j=0,sum=0,ans=n;
        while(1)
        {
            if(sum>x)
                ans=min(ans,j-i);
            if(sum>x)
                sum-=arr[i++];
            else
                sum+=arr[j++];
            if((j==n && sum<=x) || i==n)
                break;
        }
        if(sum>x)
            ans=min(ans,j-i);
        cout << ans << '\n';
    }
}
