#include<bits/stdc++.h>
using namespace std;

int findPair(int arr[],int n,int x)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(abs(arr[j]-arr[i])==x)
                return 1;
        }
    }
    return -1;
}

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
        cout << findPair(arr,n,x) << '\n';
    }
}