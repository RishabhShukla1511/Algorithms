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
        int arr[n];
        for(int i=0;i<n;i++)
            cin >> arr[i];
        ll sum=0;
        int left[n],right[n];
        left[0]=arr[0];
        for(int i=1;i<n;i++)
            left[i]=max(left[i-1],arr[i]);
        right[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
            right[i]=max(right[i+1],arr[i]);
        for(int i=0;i<n;i++)
            sum+=min(left[i],right[i])-arr[i];
        cout << sum << '\n';
    }
}
