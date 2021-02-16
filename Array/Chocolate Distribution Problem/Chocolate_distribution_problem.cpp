#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin >> arr[i];
        int m,ans=INT_MAX;
        cin >> m;
        sort(arr,arr+n);
        for(int i=0;i<n;i++)
        {
            if(i+m-1<n && arr[i+m-1]-arr[i]<ans)
                ans=arr[i+m-1]-arr[i];
        }
        cout << ans << '\n';
    }
}
