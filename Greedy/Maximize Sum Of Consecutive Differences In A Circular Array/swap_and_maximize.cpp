#include<bits/stdc++.h>
using namespace std;

int maxSumofPermt(int arr[],int n)
{
    if(n<2)
        return 0;
    sort(arr,arr+n);
    int maxsum=0,i=0,j=n-1,k=0;
    while(i!=j)
    {
        maxsum+=abs(arr[i]-arr[j]);
        if(k==0)
        {
            i++;
            k=1;
        }
        else
        {
            j--;
            k=0;
        }
    }
    maxsum+=abs(arr[i]-arr[0]);
    return maxsum;
}

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
        sort(arr,arr+n);
        cout << maxSumofPermt(arr,n) << '\n';
    }
}