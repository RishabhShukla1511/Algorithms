#include<bits/stdc++.h>
using namespace std;

int findPair(int arr[],int n,int x)
{
    sort(arr,arr+n);
    int i=0,j=1;
    while(i<n && j<n)
    {
        if(arr[j]-arr[i]==x)    
            return 1;
        else if(arr[j]-arr[i]>x)    
            i++;
        else
            j++;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(false);
    cin.tie(false);
    int t;
    cin >> t;
    while(t--)
    {
        int n,x;
        cin >> n >> x;
        int arr[n];
        for(int i=0;i<n;i++)
            cin >> arr[i];
        cout << findPair(arr,n,x) << '\n';
    }
}