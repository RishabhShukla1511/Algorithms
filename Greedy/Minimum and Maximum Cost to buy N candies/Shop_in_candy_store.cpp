#include<bits/stdc++.h>
#define fastIO() do{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);}while(0);
using namespace std;

int getCost(int arr[],int n,int k)
{
    int cost=0,j=n;
    for(int i=0;i<j;i++)
    {
        cost+=arr[i];
        j-=k;
    }
    return cost;
}

int main()
{
    fastIO();
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        int arr[n];
        for(int i=0;i<n;i++)
            cin >> arr[i];
        sort(arr,arr+n);
        cout << getCost(arr,n,k) << " ";
        reverse(arr,arr+n);
        cout << getCost(arr,n,k) << '\n';
    }
}