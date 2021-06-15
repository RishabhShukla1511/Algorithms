#include<bits/stdc++.h>
using namespace std;

int MCMutil(int arr[],int i,int j)
{
    if(i>=j)
        return 0;
    int temp=INT_MAX;
    for(int k=i;k<j;k++)
        temp=min(temp,MCMutil(arr,i,k)+MCMutil(arr,k+1,j)+arr[i-1]*arr[k]*arr[j]);
    return temp;
}

int MCM(int arr[],int n)
{
    return MCMutil(arr,1,n-1);
}

int main()
{
    int n;
    cout << "Enter the size of array\n";
    cin >> n;
    int arr[n];
    cout << "Enter the array\n";
    for(int i=0;i<n;i++)
        cin >> arr[i];
    cout << "Minimum number of multiplications required = " << MCM(arr,n);
}
