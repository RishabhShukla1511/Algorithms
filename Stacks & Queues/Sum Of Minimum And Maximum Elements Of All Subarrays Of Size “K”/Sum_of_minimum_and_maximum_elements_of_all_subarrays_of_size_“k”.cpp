#include<bits/stdc++.h>
using namespace std;

int findSum(int arr[],int n,int k)
{
    if(n==0 || k>n)
        return INT_MAX;
    int sum=0;
    for(int i=0;i<=n-k;i++)
    {
        int minv=arr[i],maxv=arr[i];
        for(int j=i;j<i+k;j++)
        {
            minv=min(minv,arr[j]);
            maxv=max(maxv,arr[j]);
        }
        sum+=minv+maxv;
    }
    return sum;
}

int main()
{
    int n;
    cout << "Enter the number of elements\n";
    cin >> n;
    int arr[n];
    cout << "Enter the elements\n";
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int k;
    cout << "Enter subarrays size\n";
    cin >> k;
    cout << "The sum of minimum and maximum elements of all subarrays of size " << k << " is: " << findSum(arr,n,k);
}