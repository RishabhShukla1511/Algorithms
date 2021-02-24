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
        auto it=lower_bound(arr,arr+n,x);
        if(it-arr==n)
            cout << "-1\n";
        else
        {
            cout << it-arr << " ";
            it=lower_bound(arr,arr+n,x+1);
            cout << it-arr-1 << '\n';
        }
    }
}