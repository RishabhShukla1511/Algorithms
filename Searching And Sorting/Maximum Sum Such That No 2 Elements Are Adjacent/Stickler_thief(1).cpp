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
        int arr[n],dp[n];
        for(int i=0;i<n;i++)
            cin >> arr[i];
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
        for(int i=2;i<n;i++)
        {
            int t1=dp[i-2]+arr[i],t2=dp[i-1];
            dp[i]=max(t1,t2);
        }
        cout << dp[n-1] << "\n";
    }
}